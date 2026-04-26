/****************************************************************************
 *
 *   Copyright 2024 The MathWorks, Inc.
 *   This file is used to create the added Parameter metadata.
 *
 ****************************************************************************/

/**
 * New group testing parameter 1.
 *
 * To check if it reflects.
 *
 * @min -1000000
 * @max 1000000
 * @group Simulink Module
 */
PARAM_DEFINE_INT32(SL_INT32_PARAM, 0);

/**
 * New group testing parameter 2.
 *
 * To check if it reflects.
 *
 * @min -1000000
 * @max 1000000
 * @group Simulink Module
 */
PARAM_DEFINE_FLOAT(SL_FLOAT_PARAM, 0.0);


/**
 * Commanded Pitch Angle
 * 
 * Commanded Pitch Angle for Flight Testing in deg
 * 
 * @unit deg
 * @min -20
 * @max 20
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(THETA_COMMAND, 4);

/**
 * Commanded Airspeed
 * 
 * Commanded True Air Speed for Flight Testing in m/s
 * 
 * @unit m/s
 * @min 10
 * @max 30
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(AIRSPEED_COMMAND, 20);

/**
 * Amplitude of Short Period Doublet
 * 
 * Amplitude of elevator doublet during short period excitation
 * 
 * @unit deg
 * @min 0
 * @max 12.5
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(SP_DOUBLET_AMP, 3);

/**
 * Frequency of short period doublet
 * 
 * Frequency of short period excitation with elevator
 * 
 * @unit Hz
 * @min 0
 * @max 10
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(SP_DOUBLET_FREQ, 1.1);

/**
 * Total duration of short period doublet
 * 
 * Total duration of short period excitation with elevator
 * 
 * @unit s
 * @min 0
 * @max 10
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(SP_DOUBLET_DUR, 2.5);

/**
 * Total duration of dutch roll doublet
 * 
 * Total duration of dutch roll excitation with rudder
 * 
 * @unit s
 * @min 0
 * @max 15
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(DR_DOUBLET_DUR, 7.5);

/**
 * Frequency of dutch roll doublet
 * 
 * Frequency of dutch roll excitation with rudder
 * 
 * @unit Hz
 * @min 0
 * @max 10
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(DR_DOUBLET_FREQ, 0.44);

/**
 * Amplitude of dutch roll doublet
 * 
 * Amplitude of dutch roll excitation with rudder
 * 
 * @unit %
 * @min 0
 * @max 100
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(DR_DOUBLET_AMP, 10);

/**
 * Amplitude of phugoid doublet
 * 
 * Amplitude of phugoid excitation with throttle
 * 
 * @unit %
 * @min 0
 * @max 100
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(PH_DOUBLET_AMP, 10);

/**
 * Frequency of phugoid doublet
 * 
 * Frequency of phugoid excitation with throttle
 * 
 * @unit Hz
 * @min 0
 * @max 10
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(PH_DOUBLET_FREQ, 0.166667);

/**
 * Total duration of phugoid doublet
 * 
 * Total duration of phugoid excitation with throttle
 * 
 * @unit s
 * @min 0
 * @max 30
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(PH_DOUBLET_DUR, 20);

/**
 * P gain of velocity PI controller
 * 
 * P gain of velocity PI controller
 * 
 * @min -1
 * @max 0
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(VEL_CONTR_GAIN_P, -0.06);

/**
 * I gain of velocity PI controller
 * 
 * I gain of velocity PI controller
 * 
 * @min -1
 * @max 0
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(VEL_CONTR_GAIN_I, -0.015);

/**
 * I gain of theta PI controller
 * 
 * I gain of theta PI controller
 * 
 * @min -10
 * @max 0
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(PITCH_CON_GAIN_I, -2.2918);

/**
 * P gain of theta PI controller
 * 
 * P gain of theta PI controller
 * 
 * @min -10
 * @max 0
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(PITCH_CON_GAIN_P, -1.3751);

/**
 * Mode for flight testing
 * 
 * Selected mode of the pilot for flight testing
 * 
 * @min 0
 * @max 9999
 * @group Flight Testing
 */
PARAM_DEFINE_FLOAT(MODE_SELECTOR, 0);
