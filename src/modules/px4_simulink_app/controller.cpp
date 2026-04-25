//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.82
// Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
// C/C++ source code generated on : Fri Apr 24 10:49:02 2026
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller.h"
#include "controller_types.h"
#include "controller_private.h"
#include "rtwtypes.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>

// Block signals (default storage)
B_controller_T controller_B;

// Block states (default storage)
DW_controller_T controller_DW;

// Real-time model
RT_MODEL_controller_T controller_M_ = RT_MODEL_controller_T();
RT_MODEL_controller_T *const controller_M = &controller_M_;

// Forward declaration for local functions
static void controll_PX4Actuators_setupImpl(px4_internal_block_PX4Actuato_T *obj);
static void rate_monotonic_scheduler(void);

//
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to remember which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void controller_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)controller_M->StepTask(1));
}

//
//         This function updates active task flag for each subrate
//         and rate transition flags for tasks that exchange data.
//         The function assumes rate-monotonic multitasking scheduler.
//         The function must be called at model base rate so that
//         the generated code self-manages all its subrates and rate
//         transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  controller_M->Timing.RateInteraction.TID0_1 =
    (controller_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (controller_M->Timing.TaskCounters.TID[1])++;
  if ((controller_M->Timing.TaskCounters.TID[1]) > 3) {// Sample time: [0.004s, 0.0s] 
    controller_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// System initialize for atomic system:
void contro_ReadParameter11_Init(DW_ReadParameter11_controller_T *localDW)
{
  static const char_T ParameterNameStr[17] = "VEL_CONTR_GAIN_I";

  // Start for MATLABSystem: '<S12>/Read Parameter11'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, 1.0);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void controller_ReadParameter11(B_ReadParameter11_controller_T *localB,
  DW_ReadParameter11_controller_T *localDW)
{
  boolean_T b_varargout_2;

  // MATLABSystem: '<S12>/Read Parameter11'
  b_varargout_2 = MW_ParamRead_Step(localDW->obj.MW_PARAMHANDLE, MW_SINGLE,
    &localB->ReadParameter11_o1);
  if (b_varargout_2) {
    localB->ReadParameter11_o1 = 0.0F;
  }

  // End of MATLABSystem: '<S12>/Read Parameter11'
}

// Termination for atomic system:
void contro_ReadParameter11_Term(DW_ReadParameter11_controller_T *localDW)
{
  // Terminate for MATLABSystem: '<S12>/Read Parameter11'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter11'
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

// Model step function for TID0
void controller_step0(void)            // Sample time: [0.001s, 0.0s]
{
  real_T temp;
  int32_T i;
  real32_T ParamStep;
  real32_T ParamStep_0;
  real32_T rtb_Converttimefromustos;
  real32_T rtb_FunctionforDeflectionValu_e;
  real32_T rtb_Kb;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation1;
  real32_T rtb_Saturation10;
  real32_T rtb_Saturation7;
  real32_T rtb_Saturation8;
  real32_T rtb_theta;
  real32_T yTemp;
  boolean_T b_varargout_1;
  boolean_T tmp;

  {                                    // Sample time: [0.001s, 0.0s]
    rate_monotonic_scheduler();
  }

  // MATLABSystem: '<S149>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_d.orbMetadataObj,
    &controller_DW.obj_d.eventStructObj, &controller_B.r1, false, 5000.0);

  // Outputs for Enabled SubSystem: '<S149>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S150>/Enable'

  // Start for MATLABSystem: '<S149>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S150>/In1'
    controller_B.In1_d = controller_B.r1;
  }

  // End of Outputs for SubSystem: '<S149>/Enabled Subsystem'

  // RateTransition generated from: '<S2>/Output Limitation' incorporates:
  //   RateTransition generated from: '<Root>/PX4 Timestamp'
  //   RateTransition generated from: '<S19>/Controller'
  //   RateTransition generated from: '<S22>/Function for Deflection Value Rudder Left'
  //   RateTransition generated from: '<S22>/Function for Deflection Value Rudder Right'
  //   RateTransition generated from: '<S2>/Control Authority Gain'

  tmp = controller_M->Timing.RateInteraction.TID0_1;
  if (tmp) {
    // RateTransition generated from: '<S2>/Output Limitation'
    for (i = 0; i < 6; i++) {
      controller_B.TmpRTBAtOutputLimitationOutport[i] =
        controller_DW.TmpRTBAtOutputLimitationOutport[i];
    }

    // End of RateTransition generated from: '<S2>/Output Limitation'
  }

  // End of RateTransition generated from: '<S2>/Output Limitation'

  // MATLABSystem: '<Root>/PX4 Actuator Write' incorporates:
  //   Constant: '<S16>/Constant'
  //   RelationalOperator: '<S16>/Compare'

  for (i = 0; i < 12; i++) {
    controller_B.motorValues[i] = (rtNaNF);
  }

  for (i = 0; i < 8; i++) {
    controller_B.servoValues[i] = (rtNaNF);
  }

  controller_B.motorValues[0] = controller_B.TmpRTBAtOutputLimitationOutport[0];
  controller_B.motorValues[1] = controller_B.TmpRTBAtOutputLimitationOutport[1];
  controller_B.servoValues[0] = controller_B.TmpRTBAtOutputLimitationOutport[2];
  controller_B.servoValues[5] = controller_B.TmpRTBAtOutputLimitationOutport[3];
  controller_B.servoValues[6] = controller_B.TmpRTBAtOutputLimitationOutport[4];
  controller_B.servoValues[7] = controller_B.TmpRTBAtOutputLimitationOutport[5];
  MW_actuators_set(controller_B.In1_d.values[4] >=
                   controller_P.CompareToConstant3_const,
                   &controller_B.motorValues[0], &controller_B.servoValues[0]);

  // End of MATLABSystem: '<Root>/PX4 Actuator Write'

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

  // Switch: '<S25>/Check for activation'
  if (!(rtb_Saturation1 > controller_P.Checkforactivation_Threshold)) {
    // Switch: '<S25>/Check for activation'
    controller_DW.Savedpitchinput_PreviousInput = rtb_Saturation8;
  }

  // End of Switch: '<S25>/Check for activation'

  // MATLABSystem: '<S14>/Read Parameter2'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ms.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0.0F;
  }

  // MATLABSystem: '<S14>/Modulo by Constant' incorporates:
  //   MATLABSystem: '<S14>/Read Parameter2'
  //
  if (rtIsNaNF(ParamStep) || rtIsInfF(ParamStep)) {
    yTemp = (rtNaNF);
  } else {
    yTemp = static_cast<real32_T>(fmod(static_cast<real_T>(ParamStep), 3.0));
    if (yTemp == 0.0F) {
      yTemp = 0.0F;
    } else if (yTemp < 0.0F) {
      yTemp += 3.0F;
    }
  }

  // Switch: '<S14>/Switch4' incorporates:
  //   Constant: '<S14>/Constant6'
  //   Constant: '<S14>/Constant7'
  //   MATLABSystem: '<S14>/Read Parameter2'
  //
  if (ParamStep > controller_P.Switch4_Threshold) {
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

  // Switch: '<S27>/Check for activation'
  if (!(rtb_Saturation1 > controller_P.Checkforactivation_Threshold_d)) {
    // Switch: '<S27>/Check for activation'
    controller_DW.Savedyawinput_PreviousInput = rtb_Saturation7;
  }

  // End of Switch: '<S27>/Check for activation'

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

  // Switch: '<S26>/Check for activation'
  if (!(rtb_Saturation1 > controller_P.Checkforactivation_Threshold_m)) {
    // Switch: '<S26>/Check for activation'
    controller_DW.SavedThrustinput_PreviousInput = rtb_Saturation10;
  }

  // End of Switch: '<S26>/Check for activation'

  // RateTransition generated from: '<Root>/PX4 Timestamp'
  if (tmp) {
    // RateTransition generated from: '<Root>/PX4 Timestamp'
    controller_B.TmpRTBAtPX4TimestampOutport1 =
      controller_DW.TmpRTBAtPX4TimestampOutport1_Bu;
  }

  // Switch: '<S29>/Give stored time instead  of current time after activation'
  if (!(rtb_Saturation1 > controller_P.Givestoredtimeinsteadofcurrentt)) {
    // Switch: '<S29>/Give stored time instead  of current time after activation' incorporates:
    //   RateTransition generated from: '<Root>/PX4 Timestamp'

    controller_DW.StoreStartTime_PreviousInput =
      controller_B.TmpRTBAtPX4TimestampOutport1;
  }

  // End of Switch: '<S29>/Give stored time instead  of current time after activation' 

  // Gain: '<S29>/Convert time from us to s' incorporates:
  //   DataTypeConversion: '<S29>/Convert time from  uint64 to single'
  //   RateTransition generated from: '<Root>/PX4 Timestamp'
  //   Sum: '<S29>/Get difference between  activation time and current time'
  //   Switch: '<S29>/Give stored time instead  of current time after activation'

  rtb_Converttimefromustos = static_cast<real32_T>
    (controller_B.TmpRTBAtPX4TimestampOutport1 -
     controller_DW.StoreStartTime_PreviousInput) *
    controller_P.Converttimefromustos_Gain;

  // MATLABSystem: '<S12>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_a.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer11' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double2'
  //   MATLABSystem: '<S12>/Read Parameter1'
  //   Product: '<S12>/Reciprocal2'
  //
  controller_InstP.short_period_period = static_cast<real32_T>(1.0 / ParamStep);

  // MATLABSystem: '<S12>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ng.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double1'
  //   Gain: '<S12>/Gain'
  //   MATLABSystem: '<S12>/Read Parameter'
  //
  controller_InstP.short_period_amp = controller_P.Gain_Gain * ParamStep_0;

  // MATLABSystem: '<S12>/Read Parameter6'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_pe.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer6' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double7'
  //   Gain: '<S12>/Gain2'
  //   MATLABSystem: '<S12>/Read Parameter6'
  //
  controller_InstP.phugoid_amp = controller_P.Gain2_Gain * ParamStep_0;

  // MATLABSystem: '<S12>/Read Parameter7'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_l1.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer9' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double8'
  //   MATLABSystem: '<S12>/Read Parameter7'
  //   Product: '<S12>/Reciprocal'
  //
  controller_InstP.phugoid_period = static_cast<real32_T>(1.0 / ParamStep_0);

  // ParameterWriter: '<S12>/Parameter Writer7' incorporates:
  //   MATLABSystem: '<S12>/Read Parameter7'
  //
  controller_InstP.phugoid_freq = ParamStep_0;

  // MATLABSystem: '<S12>/Read Parameter3'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_f.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer3' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double4'
  //   Gain: '<S12>/Gain1'
  //   MATLABSystem: '<S12>/Read Parameter3'
  //
  controller_InstP.dutch_roll_amp = controller_P.Gain1_Gain * ParamStep_0;

  // MATLABSystem: '<S12>/Read Parameter4'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_e.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // ParameterWriter: '<S12>/Parameter Writer4' incorporates:
  //   MATLABSystem: '<S12>/Read Parameter4'
  //
  controller_InstP.dutch_roll_freq = ParamStep_0;

  // MATLABSystem: '<S12>/Read Parameter2' incorporates:
  //   ParameterWriter: '<S12>/Parameter Writer2'

  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_ju.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.short_period_dur);
  if (b_varargout_1) {
    controller_InstP.short_period_dur = 0.0F;
  }

  // End of MATLABSystem: '<S12>/Read Parameter2'

  // MATLABSystem: '<S12>/Read Parameter5' incorporates:
  //   ParameterWriter: '<S12>/Parameter Writer5'

  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_o5.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.dutch_roll_dur);
  if (b_varargout_1) {
    controller_InstP.dutch_roll_dur = 0.0F;
  }

  // End of MATLABSystem: '<S12>/Read Parameter5'

  // MATLABSystem: '<S12>/Read Parameter8' incorporates:
  //   ParameterWriter: '<S12>/Parameter Writer8'

  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_p.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.phugoid_dur);
  if (b_varargout_1) {
    controller_InstP.phugoid_dur = 0.0F;
  }

  // End of MATLABSystem: '<S12>/Read Parameter8'

  // ParameterWriter: '<S12>/Parameter Writer10' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double5'
  //   MATLABSystem: '<S12>/Read Parameter4'
  //   Product: '<S12>/Reciprocal1'
  //
  controller_InstP.dutch_roll_period = static_cast<real32_T>(1.0 / ParamStep_0);

  // ParameterWriter: '<S12>/Parameter Writer1' incorporates:
  //   MATLABSystem: '<S12>/Read Parameter1'
  //
  controller_InstP.short_period_freq = ParamStep;

  // If: '<S19>/Activate different control logics after activation flag is triggered' 
  if ((rtb_Saturation1 > 0.5F) && (rtb_Saturation < 0.5F)) {
    // Outputs for IfAction SubSystem: '<S19>/Mode Selection - SysID' incorporates:
    //   ActionPort: '<S28>/Action Port'

    // If: '<S28>/Set if condition for mode to be chosen' incorporates:
    //   MATLABSystem: '<S14>/Modulo by Constant'

    if ((yTemp >= -0.5F) && (yTemp < 0.5F)) {
      // Outputs for IfAction SubSystem: '<S28>/Short Period Doublet' incorporates:
      //   ActionPort: '<S142>/Action Port'

      // Switch: '<S142>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.short_period_dur)) {
        // Switch: '<S142>/Set end time of doublet' incorporates:
        //   DataTypeConversion: '<S142>/Cast To Single'
        //   SignalGenerator: '<S142>/Doublet Generator'
        //   Sum: '<S142>/Sum Initial Pitch Input  and Doublet Wave'

        if (rtb_Converttimefromustos >= controller_InstP.short_period_period) {
          rtb_Saturation8 = controller_DW.Savedpitchinput_PreviousInput;
        } else {
          // SignalGenerator: '<S142>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S142>/Cast To Double'

          temp = controller_InstP.short_period_freq * rtb_Converttimefromustos;
          if (temp - floor(temp) >= 0.5) {
            temp = controller_InstP.short_period_amp;
          } else {
            temp = -controller_InstP.short_period_amp;
          }

          rtb_Saturation8 = controller_DW.Savedpitchinput_PreviousInput +
            static_cast<real32_T>(temp);
        }

        // End of Switch: '<S142>/Set end time of doublet'
      }

      // End of Switch: '<S142>/Set time to re-allow  pilot inputs'
      // End of Outputs for SubSystem: '<S28>/Short Period Doublet'
    } else if ((yTemp >= 0.5F) && (yTemp < 1.5F)) {
      // Outputs for IfAction SubSystem: '<S28>/Dutch Roll Doublet' incorporates:
      //   ActionPort: '<S140>/Action Port'

      // Switch: '<S140>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.dutch_roll_dur)) {
        // Switch: '<S140>/Switch1'
        if (rtb_Converttimefromustos > controller_InstP.dutch_roll_period) {
          // DataTypeConversion: '<S140>/Cast To Single1'
          rtb_Saturation7 = controller_DW.Savedyawinput_PreviousInput;
        } else {
          // SignalGenerator: '<S140>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S140>/Cast To Double'

          temp = controller_InstP.dutch_roll_freq * rtb_Converttimefromustos;
          if (temp - floor(temp) >= 0.5) {
            temp = controller_InstP.dutch_roll_amp;
          } else {
            temp = -controller_InstP.dutch_roll_amp;
          }

          // DataTypeConversion: '<S140>/Cast To Single1' incorporates:
          //   DataTypeConversion: '<S140>/Cast To Single'
          //   SignalGenerator: '<S140>/Doublet Generator'
          //   Sum: '<S140>/Sum Initial Yaw Input  and Doublet Wave'

          rtb_Saturation7 = controller_DW.Savedyawinput_PreviousInput +
            static_cast<real32_T>(temp);
        }

        // End of Switch: '<S140>/Switch1'
      }

      // End of Switch: '<S140>/Set time to re-allow  pilot inputs'
      // End of Outputs for SubSystem: '<S28>/Dutch Roll Doublet'
    } else if ((yTemp >= 1.5F) && (yTemp < 2.5F)) {
      // Outputs for IfAction SubSystem: '<S28>/Phugoid Doublet' incorporates:
      //   ActionPort: '<S141>/Action Port'

      // Switch: '<S141>/Set time to re-allow  pilot inputs'
      if (!(rtb_Converttimefromustos > controller_InstP.phugoid_dur)) {
        // Switch: '<S141>/Switch1'
        if (rtb_Converttimefromustos > controller_InstP.phugoid_period) {
          // DataTypeConversion: '<S141>/Cast To Single1'
          rtb_Saturation10 = controller_DW.SavedThrustinput_PreviousInput;
        } else {
          // SignalGenerator: '<S141>/Doublet Generator' incorporates:
          //   DataTypeConversion: '<S141>/Cast To Double'

          temp = controller_InstP.phugoid_freq * rtb_Converttimefromustos;
          if (temp - floor(temp) >= 0.5) {
            temp = controller_InstP.phugoid_amp;
          } else {
            temp = -controller_InstP.phugoid_amp;
          }

          // DataTypeConversion: '<S141>/Cast To Single1' incorporates:
          //   DataTypeConversion: '<S141>/Cast To Single'
          //   SignalGenerator: '<S141>/Doublet Generator'
          //   Sum: '<S141>/Sum Initial Thrust Input  and Doublet Wave'

          rtb_Saturation10 = controller_DW.SavedThrustinput_PreviousInput +
            static_cast<real32_T>(temp);
        }

        // End of Switch: '<S141>/Switch1'
      }

      // End of Switch: '<S141>/Set time to re-allow  pilot inputs'
      // End of Outputs for SubSystem: '<S28>/Phugoid Doublet'
    }

    // End of If: '<S28>/Set if condition for mode to be chosen'
    // End of Outputs for SubSystem: '<S19>/Mode Selection - SysID'
  }

  // End of If: '<S19>/Activate different control logics after activation flag is triggered' 

  // MATLABSystem: '<S12>/Read Parameter9' incorporates:
  //   ParameterWriter: '<S12>/Parameter Writer12'

  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_mf.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.pitch_con_gain_i);
  if (b_varargout_1) {
    controller_InstP.pitch_con_gain_i = 0.0F;
  }

  // End of MATLABSystem: '<S12>/Read Parameter9'
  controller_ReadParameter11(&controller_B.ReadParameter12,
    &controller_DW.ReadParameter12);

  // ParameterWriter: '<S12>/Parameter Writer15' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double13'

  controller_InstP.vel_con_gain_p =
    controller_B.ReadParameter12.ReadParameter11_o1;
  controller_ReadParameter11(&controller_B.ReadParameter11,
    &controller_DW.ReadParameter11);

  // ParameterWriter: '<S12>/Parameter Writer14' incorporates:
  //   DataTypeConversion: '<S12>/Cast To Double12'

  controller_InstP.vel_con_gain_i =
    controller_B.ReadParameter11.ReadParameter11_o1;

  // MATLABSystem: '<S12>/Read Parameter10' incorporates:
  //   ParameterWriter: '<S12>/Parameter Writer13'

  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_b.MW_PARAMHANDLE,
    MW_SINGLE, &controller_InstP.pitch_con_gain_p);
  if (b_varargout_1) {
    controller_InstP.pitch_con_gain_p = 0.0F;
  }

  // End of MATLABSystem: '<S12>/Read Parameter10'

  // MATLABSystem: '<S151>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_l.orbMetadataObj,
    &controller_DW.obj_l.eventStructObj, &controller_B.r, false, 1.0);

  // Outputs for Enabled SubSystem: '<S151>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S152>/Enable'

  // Start for MATLABSystem: '<S151>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S152>/In1'
    controller_B.In1 = controller_B.r;
  }

  // End of Outputs for SubSystem: '<S151>/Enabled Subsystem'

  // MATLAB Function: '<S2>/quat2eul'
  rtb_theta = static_cast<real32_T>(asin(static_cast<real_T>
    ((controller_B.In1.q[1] * controller_B.In1.q[3] - controller_B.In1.q[0] *
      controller_B.In1.q[2]) * -2.0F)));

  // MATLABSystem: '<S143>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_DW.obj_m.orbMetadataObj,
    &controller_DW.obj_m.eventStructObj, &controller_B.r4, false, 1.0);

  // Outputs for Enabled SubSystem: '<S143>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S144>/Enable'

  // Start for MATLABSystem: '<S143>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S144>/In1'
    controller_B.In1_m = controller_B.r4;
  }

  // End of Outputs for SubSystem: '<S143>/Enabled Subsystem'

  // MATLABSystem: '<S14>/Read Parameter'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_n.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep);
  if (b_varargout_1) {
    ParamStep = 0.0F;
  }

  // MATLABSystem: '<S14>/Read Parameter1'
  b_varargout_1 = MW_ParamRead_Step(controller_DW.obj_k.MW_PARAMHANDLE,
    MW_SINGLE, &ParamStep_0);
  if (b_varargout_1) {
    ParamStep_0 = 0.0F;
  }

  // Outputs for Atomic SubSystem: '<S19>/Controller'
  // Sum: '<S32>/Sum' incorporates:
  //   MATLABSystem: '<S14>/Read Parameter1'
  //
  rtb_FunctionforDeflectionValu_e = ParamStep_0 -
    controller_B.In1_m.true_airspeed_m_s;

  // DiscreteIntegrator: '<S121>/Integrator'
  if (controller_DW.Integrator_IC_LOADING != 0) {
    controller_DW.Integrator_DSTATE = rtb_theta;
  }

  if ((rtb_Saturation1 > 0.0F) && (controller_DW.Integrator_PrevResetState <= 0))
  {
    controller_DW.Integrator_DSTATE = rtb_theta;
  }

  // Sum: '<S130>/Sum' incorporates:
  //   DiscreteIntegrator: '<S121>/Integrator'
  //   Gain: '<S126>/Proportional Gain'

  rtb_Converttimefromustos = controller_InstP.vel_con_gain_p *
    rtb_FunctionforDeflectionValu_e + controller_DW.Integrator_DSTATE;

  // Saturate: '<S128>/Saturation'
  if (rtb_Converttimefromustos > controller_P.PIDController_UpperSaturationLi) {
    ParamStep_0 = controller_P.PIDController_UpperSaturationLi;
  } else if (rtb_Converttimefromustos <
             controller_P.PIDController_LowerSaturationLi) {
    ParamStep_0 = controller_P.PIDController_LowerSaturationLi;
  } else {
    ParamStep_0 = rtb_Converttimefromustos;
  }

  // End of Saturate: '<S128>/Saturation'

  // Gain: '<S113>/Kb' incorporates:
  //   Sum: '<S113>/SumI2'

  rtb_Kb = (ParamStep_0 - rtb_Converttimefromustos) *
    controller_P.PIDController_Kb;

  // Switch: '<S30>/Switch' incorporates:
  //   Gain: '<S18>/Gain1'
  //   MATLABSystem: '<S14>/Modulo by Constant'
  //   MATLABSystem: '<S14>/Read Parameter'
  //
  if (!(yTemp > controller_P.Switch_Threshold_k)) {
    ParamStep_0 = controller_P.Gain1_Gain_o * ParamStep;
  }

  // End of Switch: '<S30>/Switch'

  // Sum: '<S31>/Sum'
  ParamStep_0 -= rtb_theta;

  // DiscreteIntegrator: '<S68>/Integrator'
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

  // Sum: '<S77>/Sum' incorporates:
  //   DiscreteIntegrator: '<S68>/Integrator'
  //   Gain: '<S73>/Proportional Gain'

  rtb_Converttimefromustos = controller_InstP.pitch_con_gain_p * ParamStep_0 +
    controller_DW.Integrator_DSTATE_e;

  // Saturate: '<S75>/Saturation'
  if (rtb_Converttimefromustos > controller_P.PIDController_UpperSaturation_d) {
    ParamStep = controller_P.PIDController_UpperSaturation_d;
  } else if (rtb_Converttimefromustos <
             controller_P.PIDController_LowerSaturation_m) {
    ParamStep = controller_P.PIDController_LowerSaturation_m;
  } else {
    ParamStep = rtb_Converttimefromustos;
  }

  // End of Saturate: '<S75>/Saturation'

  // Update for DiscreteIntegrator: '<S121>/Integrator' incorporates:
  //   DiscreteIntegrator: '<S68>/Integrator'
  //   Gain: '<S118>/Integral Gain'
  //   Sum: '<S113>/SumI4'

  controller_DW.Integrator_IC_LOADING = 0U;
  controller_DW.Integrator_DSTATE += (controller_InstP.vel_con_gain_i *
    rtb_FunctionforDeflectionValu_e + rtb_Kb) * controller_P.Integrator_gainval;
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

  // End of Update for DiscreteIntegrator: '<S121>/Integrator'

  // Update for DiscreteIntegrator: '<S68>/Integrator' incorporates:
  //   Gain: '<S60>/Kb'
  //   Gain: '<S65>/Integral Gain'
  //   Sum: '<S60>/SumI2'
  //   Sum: '<S60>/SumI4'

  controller_DW.Integrator_IC_LOADING_p = 0U;
  controller_DW.Integrator_DSTATE_e += ((ParamStep - rtb_Converttimefromustos) *
    controller_P.PIDController_Kb_c + controller_InstP.pitch_con_gain_i *
    ParamStep_0) * controller_P.Integrator_gainval_b;

  // End of Outputs for SubSystem: '<S19>/Controller'

  // RateTransition generated from: '<S19>/Controller'
  if (tmp) {
    // Outputs for Atomic SubSystem: '<S19>/Controller'
    // Switch: '<S23>/Switch3'
    if (rtb_Saturation > controller_P.Switch3_Threshold) {
      // Switch: '<S23>/Switch2' incorporates:
      //   Constant: '<S23>/Constant'

      if (rtb_Saturation1 > controller_P.Switch2_Threshold) {
        controller_DW.TmpRTBAtControllerOutport2_Buff =
          controller_P.Constant_Value_b;
      } else {
        controller_DW.TmpRTBAtControllerOutport2_Buff = rtb_Saturation10;
      }

      // End of Switch: '<S23>/Switch2'
    } else {
      controller_DW.TmpRTBAtControllerOutport2_Buff = rtb_Saturation10;
    }

    // End of Switch: '<S23>/Switch3'
    // End of Outputs for SubSystem: '<S19>/Controller'
  }

  // Outputs for Atomic SubSystem: '<S19>/Controller'
  // Switch: '<S23>/Switch1'
  if (rtb_Saturation > controller_P.Switch1_Threshold) {
    // Switch: '<S23>/Switch'
    if (rtb_Saturation1 > controller_P.Switch_Threshold) {
      rtb_Saturation8 = ParamStep;
    }

    // End of Switch: '<S23>/Switch'
  }

  // Gain: '<S21>/Pitch control portion' incorporates:
  //   Switch: '<S23>/Switch1'

  ParamStep_0 = controller_P.Pitchcontrolportion_Gain * rtb_Saturation8;

  // End of Outputs for SubSystem: '<S19>/Controller'

  // Fcn: '<S13>/Fcn2' incorporates:
  //   DataTypeConversion: '<S13>/Data Type Conversion'

  rtb_Saturation1 = (static_cast<real32_T>(controller_B.In1_d.values[0]) -
                     1500.0F) / 500.0F;

  // Saturate: '<S13>/Saturation9'
  if (rtb_Saturation1 > controller_P.Saturation9_UpperSat) {
    rtb_Saturation1 = controller_P.Saturation9_UpperSat;
  } else if (rtb_Saturation1 < controller_P.Saturation9_LowerSat) {
    rtb_Saturation1 = controller_P.Saturation9_LowerSat;
  }

  // Gain: '<S21>/Roll control portion' incorporates:
  //   Gain: '<S13>/Gain'
  //   Saturate: '<S13>/Saturation9'

  rtb_Converttimefromustos = controller_P.Gain_Gain_h * rtb_Saturation1 *
    controller_P.Rollcontrolportion_Gain;

  // Sum: '<S21>/Add Elevon Left'
  rtb_Saturation1 = rtb_Converttimefromustos - ParamStep_0;

  // Sum: '<S21>/Add Elevon Right'
  rtb_Converttimefromustos = (0.0F - rtb_Converttimefromustos) - ParamStep_0;

  // RateTransition generated from: '<S2>/Control Authority Gain'
  if (tmp) {
    controller_DW.TmpRTBAtControlAuthorityGainInp[0] = rtb_Saturation1;
    controller_DW.TmpRTBAtControlAuthorityGainInp[1] = rtb_Converttimefromustos;
  }

  // Fcn: '<S14>/Fcn7' incorporates:
  //   DataTypeConversion: '<S14>/Cast To Single'

  rtb_Saturation1 = (static_cast<real32_T>(controller_B.In1_d.values[5]) -
                     1000.0F) / 500.0F;

  // Saturate: '<S14>/Saturation7'
  if (rtb_Saturation1 > controller_P.Saturation7_UpperSat_m) {
    rtb_Saturation1 = controller_P.Saturation7_UpperSat_m;
  } else if (rtb_Saturation1 < controller_P.Saturation7_LowerSat_b) {
    rtb_Saturation1 = controller_P.Saturation7_LowerSat_b;
  }

  // Switch: '<S22>/Switch' incorporates:
  //   Constant: '<S22>/No Rudder Deflection Value'
  //   Constant: '<S22>/Spoiler Rudder Deflection Value'
  //   Saturate: '<S14>/Saturation7'

  if (rtb_Saturation1 > controller_P.Switch_Threshold_j) {
    ParamStep_0 = controller_P.SpoilerRudderDeflectionValue_Va;
  } else {
    ParamStep_0 = controller_P.NoRudderDeflectionValue_Value;
  }

  // End of Switch: '<S22>/Switch'

  // RateTransition generated from: '<S22>/Function for Deflection Value Rudder Right' incorporates:
  //   Fcn: '<S22>/Function for Deflection Value Rudder Right'
  //   Sum: '<S22>/Add'
  //   Switch: '<S22>/Deflection Logic Rudder Right'

  if (tmp) {
    // Switch: '<S22>/Deflection Logic Rudder Right' incorporates:
    //   Constant: '<S22>/No Rudder Deflection Value'

    if (rtb_Saturation7 > controller_P.DeflectionLogicRudderRight_Thre) {
      rtb_Saturation1 = rtb_Saturation7;
    } else {
      rtb_Saturation1 = controller_P.NoRudderDeflectionValue_Value;
    }

    controller_DW.TmpRTBAtFunctionforDeflectionVa = ((rtb_Saturation1 +
      ParamStep_0) - 0.5F) * 2.0F;
  }

  // Gain: '<S22>/Reverse for Rudder Left'
  rtb_Saturation7 *= controller_P.ReverseforRudderLeft_Gain;

  // RateTransition generated from: '<S22>/Function for Deflection Value Rudder Left' incorporates:
  //   Fcn: '<S22>/Function for Deflection Value Rudder Left'
  //   Sum: '<S22>/Add1'
  //   Switch: '<S22>/Deflection Logic Rudder Left'

  if (tmp) {
    // Switch: '<S22>/Deflection Logic Rudder Left' incorporates:
    //   Constant: '<S22>/No Rudder Deflection Value'

    if (!(rtb_Saturation7 > controller_P.DeflectionLogicRudderLeft_Thres)) {
      rtb_Saturation7 = controller_P.NoRudderDeflectionValue_Value;
    }

    controller_DW.TmpRTBAtFunctionforDeflection_m = ((ParamStep_0 +
      rtb_Saturation7) - 0.5F) * 2.0F;
  }

  // MATLABSystem: '<S145>/SourceBlock'
  uORB_read_step(controller_DW.obj_j.orbMetadataObj,
                 &controller_DW.obj_j.eventStructObj, &controller_B.r1, false,
                 1.0);
}

// Model step function for TID1
void controller_step1(void)            // Sample time: [0.004s, 0.0s]
{
  real32_T rtb_OutputLimitation[6];
  real32_T u0;

  // Saturate: '<S2>/Output Limitation'
  if (controller_DW.TmpRTBAtControllerOutport2_Buff >
      controller_P.OutputLimitation_UpperSat) {
    rtb_OutputLimitation[0] = controller_P.OutputLimitation_UpperSat;
    rtb_OutputLimitation[1] = controller_P.OutputLimitation_UpperSat;
  } else if (controller_DW.TmpRTBAtControllerOutport2_Buff <
             controller_P.OutputLimitation_LowerSat) {
    rtb_OutputLimitation[0] = controller_P.OutputLimitation_LowerSat;
    rtb_OutputLimitation[1] = controller_P.OutputLimitation_LowerSat;
  } else {
    rtb_OutputLimitation[0] = controller_DW.TmpRTBAtControllerOutport2_Buff;
    rtb_OutputLimitation[1] = controller_DW.TmpRTBAtControllerOutport2_Buff;
  }

  // Gain: '<S2>/Control Authority Gain' incorporates:
  //   RateTransition generated from: '<S2>/Control Authority Gain'

  u0 = controller_P.ControlAuthorityGain_Gain *
    controller_DW.TmpRTBAtControlAuthorityGainInp[0];

  // Saturate: '<S2>/Output Limitation'
  if (u0 > controller_P.OutputLimitation_UpperSat) {
    rtb_OutputLimitation[2] = controller_P.OutputLimitation_UpperSat;
  } else if (u0 < controller_P.OutputLimitation_LowerSat) {
    rtb_OutputLimitation[2] = controller_P.OutputLimitation_LowerSat;
  } else {
    rtb_OutputLimitation[2] = u0;
  }

  // Gain: '<S2>/Control Authority Gain' incorporates:
  //   RateTransition generated from: '<S2>/Control Authority Gain'

  u0 = controller_P.ControlAuthorityGain_Gain *
    controller_DW.TmpRTBAtControlAuthorityGainInp[1];

  // Saturate: '<S2>/Output Limitation'
  if (u0 > controller_P.OutputLimitation_UpperSat) {
    rtb_OutputLimitation[3] = controller_P.OutputLimitation_UpperSat;
  } else if (u0 < controller_P.OutputLimitation_LowerSat) {
    rtb_OutputLimitation[3] = controller_P.OutputLimitation_LowerSat;
  } else {
    rtb_OutputLimitation[3] = u0;
  }

  if (controller_DW.TmpRTBAtFunctionforDeflectionVa >
      controller_P.OutputLimitation_UpperSat) {
    rtb_OutputLimitation[4] = controller_P.OutputLimitation_UpperSat;
  } else if (controller_DW.TmpRTBAtFunctionforDeflectionVa <
             controller_P.OutputLimitation_LowerSat) {
    rtb_OutputLimitation[4] = controller_P.OutputLimitation_LowerSat;
  } else {
    rtb_OutputLimitation[4] = controller_DW.TmpRTBAtFunctionforDeflectionVa;
  }

  if (controller_DW.TmpRTBAtFunctionforDeflection_m >
      controller_P.OutputLimitation_UpperSat) {
    rtb_OutputLimitation[5] = controller_P.OutputLimitation_UpperSat;
  } else if (controller_DW.TmpRTBAtFunctionforDeflection_m <
             controller_P.OutputLimitation_LowerSat) {
    rtb_OutputLimitation[5] = controller_P.OutputLimitation_LowerSat;
  } else {
    rtb_OutputLimitation[5] = controller_DW.TmpRTBAtFunctionforDeflection_m;
  }

  // RateTransition generated from: '<S2>/Output Limitation'
  for (int32_T i = 0; i < 6; i++) {
    controller_DW.TmpRTBAtOutputLimitationOutport[i] = rtb_OutputLimitation[i];
  }

  uint64_T rtb_PX4Timestamp;

  // End of RateTransition generated from: '<S2>/Output Limitation'

  // MATLABSystem: '<S6>/SourceBlock'
  uORB_read_step(controller_DW.obj_og.orbMetadataObj,
                 &controller_DW.obj_og.eventStructObj, &controller_B.r2, false,
                 1.0);

  // MATLABSystem: '<S147>/SourceBlock'
  uORB_read_step(controller_DW.obj_o.orbMetadataObj,
                 &controller_DW.obj_o.eventStructObj, &controller_B.r3, false,
                 1.0);

  // MATLABSystem: '<Root>/PX4 Timestamp'
  rtb_PX4Timestamp = hrt_absolute_time();

  // RateTransition generated from: '<Root>/PX4 Timestamp' incorporates:
  //   MATLABSystem: '<Root>/PX4 Timestamp'

  controller_DW.TmpRTBAtPX4TimestampOutport1_Bu = rtb_PX4Timestamp;
}

// Use this function only if you need to maintain compatibility with an existing static main program.
void controller_step(int_T tid)
{
  switch (tid) {
   case 0 :
    controller_step0();
    break;

   case 1 :
    controller_step1();
    break;

   default :
    // do nothing
    break;
  }
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
    static const char_T ParameterNameStr_1[15] = "SP_DOUBLET_AMP";
    static const char_T ParameterNameStr_2[15] = "PH_DOUBLET_AMP";
    static const char_T ParameterNameStr_3[16] = "PH_DOUBLET_FREQ";
    static const char_T ParameterNameStr_4[15] = "DR_DOUBLET_AMP";
    static const char_T ParameterNameStr_5[16] = "DR_DOUBLET_FREQ";
    static const char_T ParameterNameStr_6[15] = "SP_DOUBLET_DUR";
    static const char_T ParameterNameStr_7[15] = "DR_DOUBLET_DUR";
    static const char_T ParameterNameStr_8[15] = "PH_DOUBLET_DUR";
    static const char_T ParameterNameStr_9[17] = "PITCH_CON_GAIN_I";
    static const char_T ParameterNameStr_a[17] = "PITCH_CON_GAIN_P";
    static const char_T ParameterNameStr_b[14] = "THETA_COMMAND";
    static const char_T ParameterNameStr_c[17] = "AIRSPEED_COMMAND";
    int32_T i;
    for (i = 0; i < 6; i++) {
      // Start for RateTransition generated from: '<S2>/Output Limitation'
      controller_B.TmpRTBAtOutputLimitationOutport[i] =
        controller_P.TmpRTBAtOutputLimitationOutport;
    }

    // Start for RateTransition generated from: '<Root>/PX4 Timestamp'
    controller_B.TmpRTBAtPX4TimestampOutport1 =
      controller_P.TmpRTBAtPX4TimestampOutport1_In;

    // InitializeConditions for RateTransition generated from: '<S2>/Output Limitation' 
    for (i = 0; i < 6; i++) {
      controller_DW.TmpRTBAtOutputLimitationOutport[i] =
        controller_P.TmpRTBAtOutputLimitationOutport;
    }

    // End of InitializeConditions for RateTransition generated from: '<S2>/Output Limitation' 

    // InitializeConditions for Switch: '<S25>/Check for activation' incorporates:
    //   Memory: '<S25>/Saved pitch input'

    controller_DW.Savedpitchinput_PreviousInput =
      controller_P.Savedpitchinput_InitialConditio;

    // InitializeConditions for Switch: '<S27>/Check for activation' incorporates:
    //   Memory: '<S27>/Saved yaw input'

    controller_DW.Savedyawinput_PreviousInput =
      controller_P.Savedyawinput_InitialCondition;

    // InitializeConditions for Switch: '<S26>/Check for activation' incorporates:
    //   Memory: '<S26>/Saved Thrust input'

    controller_DW.SavedThrustinput_PreviousInput =
      controller_P.SavedThrustinput_InitialConditi;

    // InitializeConditions for RateTransition generated from: '<Root>/PX4 Timestamp' 
    controller_DW.TmpRTBAtPX4TimestampOutport1_Bu =
      controller_P.TmpRTBAtPX4TimestampOutport1_In;

    // InitializeConditions for Switch: '<S29>/Give stored time instead  of current time after activation' incorporates:
    //   Memory: '<S29>/Store Start Time'

    controller_DW.StoreStartTime_PreviousInput =
      controller_P.StoreStartTime_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<S19>/Controller'
    // InitializeConditions for DiscreteIntegrator: '<S121>/Integrator'
    controller_DW.Integrator_PrevResetState = 2;
    controller_DW.Integrator_IC_LOADING = 1U;

    // InitializeConditions for DiscreteIntegrator: '<S68>/Integrator'
    controller_DW.Integrator_PrevResetState_k = 2;
    controller_DW.Integrator_IC_LOADING_p = 1U;

    // End of SystemInitialize for SubSystem: '<S19>/Controller'

    // SystemInitialize for Enabled SubSystem: '<S143>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S144>/In1' incorporates:
    //   Outport: '<S144>/Out1'

    controller_B.In1_m = controller_P.Out1_Y0_io;

    // End of SystemInitialize for SubSystem: '<S143>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S149>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S150>/In1' incorporates:
    //   Outport: '<S150>/Out1'

    controller_B.In1_d = controller_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S149>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S151>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S152>/In1' incorporates:
    //   Outport: '<S152>/Out1'

    controller_B.In1 = controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S151>/Enabled Subsystem'

    // Start for MATLABSystem: '<S149>/SourceBlock'
    controller_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_DW.obj_d.isSetupComplete = false;
    controller_DW.obj_d.isInitialized = 1;
    controller_DW.obj_d.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(controller_DW.obj_d.orbMetadataObj,
                         &controller_DW.obj_d.eventStructObj);
    controller_DW.obj_d.isSetupComplete = true;

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

    // Start for MATLABSystem: '<S14>/Read Parameter2'
    controller_DW.obj_ms.matlabCodegenIsDeleted = false;
    controller_DW.obj_ms.isInitialized = 1;
    controller_DW.obj_ms.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0],
      true, 1.0);
    controller_DW.obj_ms.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter1'
    controller_DW.obj_a.matlabCodegenIsDeleted = false;
    controller_DW.obj_a.isInitialized = 1;
    controller_DW.obj_a.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0],
      true, 1.0);
    controller_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter'
    controller_DW.obj_ng.matlabCodegenIsDeleted = false;
    controller_DW.obj_ng.isInitialized = 1;
    controller_DW.obj_ng.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_1[0],
      true, 1.0);
    controller_DW.obj_ng.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter6'
    controller_DW.obj_pe.matlabCodegenIsDeleted = false;
    controller_DW.obj_pe.isInitialized = 1;
    controller_DW.obj_pe.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_2[0],
      true, 1.0);
    controller_DW.obj_pe.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter7'
    controller_DW.obj_l1.matlabCodegenIsDeleted = false;
    controller_DW.obj_l1.isInitialized = 1;
    controller_DW.obj_l1.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_3[0],
      true, 1.0);
    controller_DW.obj_l1.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter3'
    controller_DW.obj_f.matlabCodegenIsDeleted = false;
    controller_DW.obj_f.isInitialized = 1;
    controller_DW.obj_f.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_4[0],
      true, 1.0);
    controller_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter4'
    controller_DW.obj_e.matlabCodegenIsDeleted = false;
    controller_DW.obj_e.isInitialized = 1;
    controller_DW.obj_e.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_5[0],
      true, 1.0);
    controller_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter2'
    controller_DW.obj_ju.matlabCodegenIsDeleted = false;
    controller_DW.obj_ju.isInitialized = 1;
    controller_DW.obj_ju.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_6[0],
      true, 1.0);
    controller_DW.obj_ju.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter5'
    controller_DW.obj_o5.matlabCodegenIsDeleted = false;
    controller_DW.obj_o5.isInitialized = 1;
    controller_DW.obj_o5.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_7[0],
      true, 1.0);
    controller_DW.obj_o5.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter8'
    controller_DW.obj_p.matlabCodegenIsDeleted = false;
    controller_DW.obj_p.isInitialized = 1;
    controller_DW.obj_p.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_8[0],
      true, 1.0);
    controller_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/Read Parameter9'
    controller_DW.obj_mf.matlabCodegenIsDeleted = false;
    controller_DW.obj_mf.isInitialized = 1;
    controller_DW.obj_mf.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_9[0],
      true, 1.0);
    controller_DW.obj_mf.isSetupComplete = true;
    contro_ReadParameter11_Init(&controller_DW.ReadParameter12);
    contro_ReadParameter11_Init(&controller_DW.ReadParameter11);

    // Start for MATLABSystem: '<S12>/Read Parameter10'
    controller_DW.obj_b.matlabCodegenIsDeleted = false;
    controller_DW.obj_b.isInitialized = 1;
    controller_DW.obj_b.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_a[0],
      true, 1.0);
    controller_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S151>/SourceBlock'
    controller_DW.obj_l.matlabCodegenIsDeleted = false;
    controller_DW.obj_l.isSetupComplete = false;
    controller_DW.obj_l.isInitialized = 1;
    controller_DW.obj_l.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_DW.obj_l.orbMetadataObj,
                         &controller_DW.obj_l.eventStructObj);
    controller_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S143>/SourceBlock'
    controller_DW.obj_m.matlabCodegenIsDeleted = false;
    controller_DW.obj_m.isSetupComplete = false;
    controller_DW.obj_m.isInitialized = 1;
    controller_DW.obj_m.orbMetadataObj = ORB_ID(airspeed);
    uORB_read_initialize(controller_DW.obj_m.orbMetadataObj,
                         &controller_DW.obj_m.eventStructObj);
    controller_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Read Parameter'
    controller_DW.obj_n.matlabCodegenIsDeleted = false;
    controller_DW.obj_n.isInitialized = 1;
    controller_DW.obj_n.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_b[0],
      true, 1.0);
    controller_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Read Parameter1'
    controller_DW.obj_k.matlabCodegenIsDeleted = false;
    controller_DW.obj_k.isInitialized = 1;
    controller_DW.obj_k.MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_c[0],
      true, 1.0);
    controller_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S145>/SourceBlock'
    controller_DW.obj_j.matlabCodegenIsDeleted = false;
    controller_DW.obj_j.isSetupComplete = false;
    controller_DW.obj_j.isInitialized = 1;
    controller_DW.obj_j.orbMetadataObj = ORB_ID(input_rc);
    uORB_read_initialize(controller_DW.obj_j.orbMetadataObj,
                         &controller_DW.obj_j.eventStructObj);
    controller_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    controller_DW.obj_og.matlabCodegenIsDeleted = false;
    controller_DW.obj_og.isSetupComplete = false;
    controller_DW.obj_og.isInitialized = 1;
    controller_DW.obj_og.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_DW.obj_og.orbMetadataObj,
                         &controller_DW.obj_og.eventStructObj);
    controller_DW.obj_og.isSetupComplete = true;

    // Start for MATLABSystem: '<S147>/SourceBlock'
    controller_DW.obj_o.matlabCodegenIsDeleted = false;
    controller_DW.obj_o.isSetupComplete = false;
    controller_DW.obj_o.isInitialized = 1;
    controller_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_DW.obj_o.orbMetadataObj,
                         &controller_DW.obj_o.eventStructObj);
    controller_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 Timestamp'
    controller_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_DW.obj_h.isInitialized = 1;
    controller_DW.obj_h.isSetupComplete = true;
  }
}

// Model terminate function
void controller_terminate(void)
{
  int32_T i;
  real32_T servoValues[8];

  // Terminate for MATLABSystem: '<S149>/SourceBlock'
  if (!controller_DW.obj_d.matlabCodegenIsDeleted) {
    controller_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_d.isInitialized == 1) &&
        controller_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S149>/SourceBlock'

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

  // Terminate for MATLABSystem: '<S14>/Read Parameter2'
  if (!controller_DW.obj_ms.matlabCodegenIsDeleted) {
    controller_DW.obj_ms.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter2'

  // Terminate for MATLABSystem: '<S12>/Read Parameter1'
  if (!controller_DW.obj_a.matlabCodegenIsDeleted) {
    controller_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter1'

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

  // Terminate for MATLABSystem: '<S12>/Read Parameter7'
  if (!controller_DW.obj_l1.matlabCodegenIsDeleted) {
    controller_DW.obj_l1.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter7'

  // Terminate for MATLABSystem: '<S12>/Read Parameter3'
  if (!controller_DW.obj_f.matlabCodegenIsDeleted) {
    controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter3'

  // Terminate for MATLABSystem: '<S12>/Read Parameter4'
  if (!controller_DW.obj_e.matlabCodegenIsDeleted) {
    controller_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter4'

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

  // Terminate for MATLABSystem: '<S12>/Read Parameter8'
  if (!controller_DW.obj_p.matlabCodegenIsDeleted) {
    controller_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter8'

  // Terminate for MATLABSystem: '<S12>/Read Parameter9'
  if (!controller_DW.obj_mf.matlabCodegenIsDeleted) {
    controller_DW.obj_mf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter9'
  contro_ReadParameter11_Term(&controller_DW.ReadParameter12);
  contro_ReadParameter11_Term(&controller_DW.ReadParameter11);

  // Terminate for MATLABSystem: '<S12>/Read Parameter10'
  if (!controller_DW.obj_b.matlabCodegenIsDeleted) {
    controller_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/Read Parameter10'

  // Terminate for MATLABSystem: '<S151>/SourceBlock'
  if (!controller_DW.obj_l.matlabCodegenIsDeleted) {
    controller_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_l.isInitialized == 1) &&
        controller_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S151>/SourceBlock'

  // Terminate for MATLABSystem: '<S143>/SourceBlock'
  if (!controller_DW.obj_m.matlabCodegenIsDeleted) {
    controller_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_m.isInitialized == 1) &&
        controller_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S143>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/Read Parameter'
  if (!controller_DW.obj_n.matlabCodegenIsDeleted) {
    controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter'

  // Terminate for MATLABSystem: '<S14>/Read Parameter1'
  if (!controller_DW.obj_k.matlabCodegenIsDeleted) {
    controller_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Read Parameter1'

  // Terminate for MATLABSystem: '<S145>/SourceBlock'
  if (!controller_DW.obj_j.matlabCodegenIsDeleted) {
    controller_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_j.isInitialized == 1) &&
        controller_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S145>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!controller_DW.obj_og.matlabCodegenIsDeleted) {
    controller_DW.obj_og.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_og.isInitialized == 1) &&
        controller_DW.obj_og.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_og.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S147>/SourceBlock'
  if (!controller_DW.obj_o.matlabCodegenIsDeleted) {
    controller_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((controller_DW.obj_o.isInitialized == 1) &&
        controller_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&controller_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S147>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/PX4 Timestamp'
  if (!controller_DW.obj_h.matlabCodegenIsDeleted) {
    controller_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 Timestamp'
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

boolean_T RT_MODEL_controller_T::StepTask(int32_T idx) const
{
  return (Timing.TaskCounters.TID[(idx)] == 0);
}

uint8_T &RT_MODEL_controller_T::TaskCounter(int32_T idx)
{
  return (Timing.TaskCounters.TID[(idx)]);
}

//
// File trailer for generated code.
//
// [EOF]
//
