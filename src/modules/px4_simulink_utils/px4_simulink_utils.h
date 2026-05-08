/****************************************************************************
 *
 *   Copyright 2024 The MathWorks, Inc.
 *   This file is used to define the added Parameter metadata.
 *
 ****************************************************************************/

#pragma once

#include <px4_platform_common/module.h>
#include <px4_platform_common/module_params.h>
#include <px4_platform_common/getopt.h>
#include <px4_platform_common/log.h>
#include <px4_platform_common/posix.h>

#include <uORB/Subscription.hpp>
#include <uORB/topics/parameter_update.h>
#include <uORB/SubscriptionCallback.hpp>
#include <uORB/topics/sensor_combined.h>

using namespace time_literals;

extern "C" __EXPORT int px4_simulink_utils_main(int argc, char *argv[]);

class PX4SimulinkUtilityModule : public ModuleBase<PX4SimulinkUtilityModule>, public ModuleParams
{
public:
	PX4SimulinkUtilityModule(int example_param, bool example_flag);

	virtual ~PX4SimulinkUtilityModule() = default;

	/** @see ModuleBase */
	static int task_spawn(int argc, char *argv[]);

	/** @see ModuleBase */
	static PX4SimulinkUtilityModule *instantiate(int argc, char *argv[]);

	/** @see ModuleBase */
	static int custom_command(int argc, char *argv[]);

	/** @see ModuleBase */
	static int print_usage(const char *reason = nullptr);

	/** @see ModuleBase::run() */
	void run() override;

	/** @see ModuleBase::print_status() */
	int print_status() override;

private:

	/**
	 * Check for parameter changes and update them if needed.
	 * @param parameter_update_sub uorb subscription to parameter_update
	 * @param force for a parameter update
	 */
	void parameters_update(bool force = false);


	DEFINE_PARAMETERS(
		(ParamFloat<px4::params::VEL_LP_FREQ>) _param_vel_lp_freq,
		(ParamInt<px4::params::PILOT_MARKER>) _param_pilot_marker,
		(ParamFloat<px4::params::MODE_SELECTOR>) _param_mode_selector,
		(ParamFloat<px4::params::PITCH_CON_GAIN_P>) _param_pitch_con_gain_p,
		(ParamFloat<px4::params::PITCH_CON_GAIN_I>) _param_pitch_con_gain_i,
		(ParamFloat<px4::params::VEL_CONTR_GAIN_I>) _param_vel_contr_gain_i,
		(ParamFloat<px4::params::VEL_CONTR_GAIN_P>) _param_vel_contr_gain_p,
		(ParamFloat<px4::params::PH_DOUBLET_DUR>) _param_ph_doublet_dur,
		(ParamFloat<px4::params::PH_DOUBLET_FREQ>) _param_ph_doublet_freq,
		(ParamFloat<px4::params::PH_DOUBLET_AMP>) _param_ph_doublet_amp,
		(ParamFloat<px4::params::DR_DOUBLET_AMP>) _param_dr_doublet_amp,
		(ParamFloat<px4::params::DR_DOUBLET_FREQ>) _param_dr_doublet_freq,
		(ParamFloat<px4::params::DR_DOUBLET_DUR>) _param_dr_doublet_dur,
		(ParamFloat<px4::params::SP_DOUBLET_DUR>) _param_sp_doublet_dur,
		(ParamFloat<px4::params::SP_DOUBLET_FREQ>) _param_sp_doublet_freq,
		(ParamFloat<px4::params::SP_DOUBLET_AMP>) _param_sp_doublet_amp,
		(ParamFloat<px4::params::AIRSPEED_COMMAND>) _param_airspeed_command,
		(ParamFloat<px4::params::THETA_COMMAND>) _param_theta_command,
		(ParamFloat<px4::params::SL_FLOAT_PARAM>) _param_sl_float_param,
	        (ParamInt<px4::params::SL_INT32_PARAM>) _param_sl_int32_param
	)

	// Subscriptions
	uORB::SubscriptionInterval _parameter_update_sub{ORB_ID(parameter_update), 1_s};

};

