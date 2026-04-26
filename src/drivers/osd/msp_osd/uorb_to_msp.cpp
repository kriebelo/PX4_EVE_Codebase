/****************************************************************************
 *
 *   Copyright (c) 2022 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* uorb_to_msp.cpp
 *
 * Implementation file for UORB -> MSP conversion functions.
 */

// includes for mathematical manipulation
#include <drivers/drv_hrt.h>
#include <lib/geo/geo.h>
#include <lib/mathlib/mathlib.h>
// #include <lib/modes/ui.hpp> // not yet implemented in this PX4  version
#include <matrix/math.hpp>

// clock access
#include <px4_platform_common/defines.h>
using namespace time_literals;

#include "uorb_to_msp.hpp"

namespace msp_osd
{
typedef enum {
	MSP_DP_HEARTBEAT = 0,         // Release the display after clearing and updating
	MSP_DP_RELEASE = 1,         // Release the display after clearing and updating
	MSP_DP_CLEAR_SCREEN = 2,    // Clear the display
	MSP_DP_WRITE_STRING = 3,    // Write a string at given coordinates
	MSP_DP_DRAW_SCREEN = 4,     // Trigger a screen draw
	MSP_DP_OPTIONS = 5,         // Not used by Betaflight. Reserved by Ardupilot and INAV
	MSP_DP_SYS = 6,             // Display system element displayportSystemElement_e at given coordinates
	MSP_DP_COUNT,
} displayportMspSubCommand;

msp_name_t construct_display_message(const vehicle_status_s &vehicle_status,
				     const vehicle_attitude_s &vehicle_attitude,
				     const log_message_s &log_message,
				     const int log_level,
				     MessageDisplay &display)
{
	// initialize result
	msp_name_t display_message {0};

	const auto now = hrt_absolute_time();
	static uint64_t last_warning_stamp {0};

	// update arming state, flight mode, and warnings, if current
	if (vehicle_status.timestamp < (now - 1_s)) {
		display.set(MessageDisplayType::ARMING, "???");
		display.set(MessageDisplayType::FLIGHT_MODE, "???");

	} else {
		// display armed / disarmed
		if (vehicle_status.arming_state == vehicle_status_s::ARMING_STATE_ARMED) {
			display.set(MessageDisplayType::ARMING, "ARM");

		} else {
			display.set(MessageDisplayType::ARMING, "DSRM");
		}

		// display flight mode
		// display.set(MessageDisplayType::FLIGHT_MODE, mode_util::nav_state_names[vehicle_status.nav_state]);
		// display flight mode (Vereinfacht für v1.14.3)
		const char* custom_mode_name = "MODE";
		switch (vehicle_status.nav_state) {
		case vehicle_status_s::NAVIGATION_STATE_MANUAL:   custom_mode_name = "MANUAL"; break;
		case vehicle_status_s::NAVIGATION_STATE_ALTCTL:   custom_mode_name = "ALTCTL"; break;
		case vehicle_status_s::NAVIGATION_STATE_POSCTL:   custom_mode_name = "POSCTL"; break;
		case vehicle_status_s::NAVIGATION_STATE_AUTO_RTL: custom_mode_name = "RTL"; break;
		case vehicle_status_s::NAVIGATION_STATE_ACRO:     custom_mode_name = "ACRO"; break;
		default:                                          custom_mode_name = "EVE"; break;
		}
		display.set(MessageDisplayType::FLIGHT_MODE, custom_mode_name);
			}

	// display, if updated
	if (log_message.severity <= log_level) {
		display.set(MessageDisplayType::WARNING, log_message.text);
		last_warning_stamp = now;

	} else if (now - last_warning_stamp > 30_s) {
		// clear warning after timeout
		display.set(MessageDisplayType::WARNING, "");
		last_warning_stamp = now;
	}

	// update heading, if relatively recent
	if (vehicle_attitude.timestamp < (now - 1_s)) {
		display.set(MessageDisplayType::HEADING, "N?");

	} else {
		// convert to YAW
		matrix::Eulerf euler_attitude(matrix::Quatf(vehicle_attitude.q));
		const auto yaw = math::degrees(euler_attitude.psi());

		// display north direction
		if (yaw <= 22.5f) {
			display.set(MessageDisplayType::HEADING, "N");

		} else if (yaw <= 67.5f) {
			display.set(MessageDisplayType::HEADING, "NE");

		} else if (yaw <= 112.5f) {
			display.set(MessageDisplayType::HEADING, "E");

		} else if (yaw <= 157.5f) {
			display.set(MessageDisplayType::HEADING, "SE");

		} else if (yaw <= 202.5f) {
			display.set(MessageDisplayType::HEADING, "S");

		} else if (yaw <= 247.5f) {
			display.set(MessageDisplayType::HEADING, "SW");

		} else if (yaw <= 292.5f) {
			display.set(MessageDisplayType::HEADING, "W");

		} else if (yaw <= 337.5f) {
			display.set(MessageDisplayType::HEADING, "NW");

		} else if (yaw <= 360.0f) {
			display.set(MessageDisplayType::HEADING, "N");
		}
	}

	// update message and return
	display.get(display_message.craft_name, hrt_absolute_time());
	return display_message;
}

msp_fc_variant_t construct_FC_VARIANT()
{
	// initialize result
	msp_fc_variant_t variant{};

	memcpy(variant.flightControlIdentifier, "PX4", sizeof(variant.flightControlIdentifier));
	return variant;
}


msp_rendor_rssi_t construct_rendor_RSSI(const input_rc_s &input_rc)
{
	msp_rendor_rssi_t rssi{};
	rssi.screenYPosition = 0x10;
	rssi.screenXPosition = 0x02;

	snprintf(&rssi.str[0], sizeof(rssi.str), "%3d", int(input_rc.rssi));
	rssi.str[3] = '%';

	return rssi;
}


msp_rendor_battery_state_t construct_rendor_BATTERY_STATE(const battery_status_s &battery_status)
{
	// initialize result
	msp_rendor_battery_state_t battery_state = {0};

	battery_state.subCommand = MSP_DP_WRITE_STRING; // 3 write string. fixed
	battery_state.screenYPosition = 0x02;
	battery_state.screenXPosition = 0x02;
	battery_state.iconAttrs = 0x00;

	float sigle_cell_v = battery_status.voltage_v / battery_status.cell_count;

	if (sigle_cell_v > 4.0f) {
		battery_state.iconIndex = 0x91; // Full battery Icon

	} else if ((sigle_cell_v <= 4.0f) && (sigle_cell_v > 3.5f)) {
		battery_state.iconIndex = 0x93; // Half battery Icon

	} else if ((sigle_cell_v <= 3.5f) && (sigle_cell_v > 3.2f)) {
		battery_state.iconIndex = 0x95; // Empty battery Icon

	} else {
		battery_state.iconIndex = 0x96; // Dead battery Icon
	}

	snprintf(&battery_state.str[0], sizeof(battery_state.str), "%.2f\x06", (double)sigle_cell_v);
	return battery_state;
}

msp_rendor_battery_state_t construct_rendor_BATTERY2_STATE(const battery_status_s &battery_status2)
{
        // initialize result
        msp_rendor_battery_state_t battery_state = {0};

        battery_state.subCommand = MSP_DP_WRITE_STRING; // 3 write string. fixed

        // Wir setzen die zweite Batterie direkt unter die Erste (Y von 0x04 auf 0x05 erhöht)
        battery_state.screenYPosition = 0x06;
        battery_state.screenXPosition = 0x02;
        battery_state.iconAttrs = 0x00;

        float single_cell_v = battery_status2.voltage_v / battery_status2.cell_count;

        // Gleiche Icon-Logik wie bei Batterie 1
        if (single_cell_v > 4.0f) {
                battery_state.iconIndex = 0x91; // Full battery Icon
        } else if ((single_cell_v <= 4.0f) && (single_cell_v > 3.5f)) {
                battery_state.iconIndex = 0x93; // Half battery Icon
        } else if ((single_cell_v <= 3.5f) && (single_cell_v > 3.2f)) {
                battery_state.iconIndex = 0x95; // Empty battery Icon
        } else {
                battery_state.iconIndex = 0x96; // Dead battery Icon
        }

        // Wir schreiben ein "B2:" davor, damit man sie im OSD unterscheiden kann
        snprintf(&battery_state.str[0], sizeof(battery_state.str), "%.2f\x06", (double)single_cell_v);
        return battery_state;
}


msp_rendor_latitude_t construct_rendor_GPS_LAT(const sensor_gps_s &vehicle_gps_position)
{
	msp_rendor_latitude_t lat{};

	lat.screenYPosition = 0x07;
	lat.screenXPosition = 0x29;

	if (vehicle_gps_position.fix_type >= 2) {
		snprintf(&lat.str[0], sizeof(lat.str), "%.6f", vehicle_gps_position.lat * 1e-7);
	} else {
		snprintf(&lat.str[0], sizeof(lat.str), "%.6f", 0.0);
	}

	return lat;
}

msp_rendor_longitude_t construct_rendor_GPS_LON(const sensor_gps_s &vehicle_gps_position)
{
	msp_rendor_longitude_t lon{};

	lon.screenYPosition = 0x06;
	lon.screenXPosition = 0x29;

	if (vehicle_gps_position.fix_type >= 2) {
		snprintf(&lon.str[0], sizeof(lon.str), "%.6f", vehicle_gps_position.lon * 1e-7);

	} else {
		snprintf(&lon.str[0], sizeof(lon.str), "%.6f", -0.0);
	}

	return lon;
}

msp_rendor_satellites_used_t construct_rendor_GPS_NUM(const sensor_gps_s &vehicle_gps_position)
{
	msp_rendor_satellites_used_t num{};

	num.screenYPosition = 0x05;
	num.screenXPosition = 0x29;

	memset(&num.str[0], 0, sizeof(num.str));
	snprintf(&num.str[0], sizeof(num.str), "%d", vehicle_gps_position.satellites_used);

	return num;
}

msp_rendor_airspeed_t construct_rendor_AIRSPEED(const airspeed_validated_s &airspeed_validated)
{
        // Initialisiert automatisch subCommand, iconAttrs und iconIndex durch die Struct-Definition!
        msp_rendor_airspeed_t as{};

        as.screenYPosition = 0x03; // Passe die Zeile an dein Wunsch-Layout an
        as.screenXPosition = 0x1C; // Passe die Spalte an

        // --- Low-Pass Filter ---
        static float filtered_ias = 0.0f;
        static bool is_filter_initialized = false;

        if (PX4_ISFINITE(airspeed_validated.indicated_airspeed_m_s) && airspeed_validated.indicated_airspeed_m_s >= 0.0f) {
                float current_ias = airspeed_validated.indicated_airspeed_m_s;

                if (!is_filter_initialized) {
                        filtered_ias = current_ias;
                        is_filter_initialized = true;
                } else {
                        // Der Filter: 5% neuer Wert, 95% alter Wert
                        filtered_ias = (0.05f * current_ias) + (0.95f * filtered_ias);
                }
        } else {
                filtered_ias = 0.0f;
        }

        memset(&as.str[0], 0, sizeof(as.str));

        // %4.1f reserviert Platz für die Zahl (z.B. " 5.2" oder "12.5")
        // \x9F druckt direkt dahinter lückenlos dein m/s Icon!
        snprintf(&as.str[0], sizeof(as.str), "%4.2f\x9F", (double)filtered_ias);

        return as;

        return as;
}



// --- 1. Distance to Home (mit dynamischem Pfeil) ---
msp_rendor_distanceToHome_t construct_rendor_distanceToHome(const home_position_s &home, const vehicle_global_position_s &pos, const vehicle_attitude_s &att)
{
        msp_rendor_distanceToHome_t dth{};
        dth.screenYPosition = 0x0B; // Anpassen
        dth.screenXPosition = 0x29; // Anpassen

        if (home.valid_hpos && home.valid_lpos) {
                // Distanz berechnen
                float dist_m = get_distance_to_next_waypoint(pos.lat, pos.lon, home.lat, home.lon);

                // Winkel zum Home-Punkt berechnen
                float bearing_to_home = get_bearing_to_next_waypoint(pos.lat, pos.lon, home.lat, home.lon);

                // Aktuelles Heading der Drohne berechnen
                matrix::Eulerf euler(matrix::Quatf(att.q));
                float heading = euler.psi(); // in Radiant

                // Relativen Winkel berechnen (Wo ist Home im Vergleich zu meiner Schnauze?)
		float relative_bearing = math::degrees(matrix::wrap_pi(bearing_to_home - heading));
                if (relative_bearing < 0.0f) relative_bearing += 360.0f;

                // Pfeil-Icon bestimmen (Betaflight nutzt 0x60 bis 0x6F für die 16 Pfeile)
                // 360 Grad / 16 Pfeile = 22.5 Grad pro Pfeil. +11.25 zur Rundung.
                uint8_t arrow_index = ((int)((relative_bearing + 11.25f) / 22.5f)) % 16;
                dth.iconIndex = 0x60 + arrow_index; // Das Icon dreht sich jetzt mit!

                // Text formatieren (über 1000m in km anzeigen)
                if (dist_m > 1000.0f) {
                        snprintf(&dth.str[0], sizeof(dth.str), "%.1fKM", (double)(dist_m / 1000.0f));
                } else {
                        snprintf(&dth.str[0], sizeof(dth.str), "%.0fM", (double)dist_m);
                }
        } else {
                dth.iconIndex = 0x60; // Pfeil nach oben als Fallback
                snprintf(&dth.str[0], sizeof(dth.str), "---M");
        }
        return dth;
}

// --- 2. mAh Used ---
msp_rendor_mAh_used_t construct_rendor_mAh_used(const battery_status_s &bat)
{
        msp_rendor_mAh_used_t mah{};
        mah.screenYPosition = 0x04;
        mah.screenXPosition = 0x02;

        snprintf(&mah.str[0], sizeof(mah.str), "%.0f\x07", (double)bat.discharged_mah);
        return mah;
}

msp_rendor_mAh_used_t construct_rendor_mAh_used2(const battery_status_s &bat)
{
        msp_rendor_mAh_used_t mah{};
        mah.screenYPosition = 0x08;
        mah.screenXPosition = 0x02;

        snprintf(&mah.str[0], sizeof(mah.str), "%.0f\x07", (double)bat.discharged_mah);
        return mah;
}

// --- 3. Amperemeter (Aktueller Strom) ---
msp_rendor_Amp_t construct_rendor_Amp(const battery_status_s &bat)
{
        msp_rendor_Amp_t amp{};
        amp.screenYPosition = 0x03;
        amp.screenXPosition = 0x02;

        snprintf(&amp.str[0], sizeof(amp.str), "%.1f\x9A", (double)bat.current_filtered_a);
        return amp;
}

msp_rendor_Amp_t construct_rendor_Amp2(const battery_status_s &bat)
{
        msp_rendor_Amp_t amp{};
        amp.screenYPosition = 0x07;
        amp.screenXPosition = 0x02;

        snprintf(&amp.str[0], sizeof(amp.str), "%.1f\x9A", (double)bat.current_filtered_a);
        return amp;
}

// --- GLOBALE VARIABLEN FÜR DISTANZ & EFFIZIENZ ---
// (Außerhalb der Funktionen definieren, damit sie geteilt werden können)
static double total_distance_m = 0.0;
static double last_lat = 0.0;
static double last_lon = 0.0;

// --- 4. Kilometer geflogen ---
msp_rendor_km_flown_t construct_rendor_km_flown(const vehicle_global_position_s &pos, const vehicle_status_s &status)
{
        msp_rendor_km_flown_t kmf{};
        kmf.screenYPosition = 0x0D;
        kmf.screenXPosition = 0x29;

        // NEU: Ein sicherer Schalter, der sich merkt, ob wir schon eine Position haben
        static bool is_pos_initialized = false;

        // Nur zählen, wenn gearmt und GPS gültig ist
        if (status.arming_state == vehicle_status_s::ARMING_STATE_ARMED) {
                // Wir prüfen jetzt den sicheren Schalter, statt die Kommazahlen!
                if (is_pos_initialized) {
                        float step_dist = get_distance_to_next_waypoint(last_lat, last_lon, pos.lat, pos.lon);
                        // Filter gegen GPS-Glitches
                        if (step_dist > 0.1f && step_dist < 50.0f) {
				total_distance_m += (double)step_dist;
			}
                }
                // Neue Koordinaten merken und Schalter auf "wahr" setzen
                last_lat = pos.lat;
                last_lon = pos.lon;
                is_pos_initialized = true;
        } else {
                // Zurücksetzen, wenn disarmt
                total_distance_m = 0.0;
                is_pos_initialized = false;
        }

        snprintf(&kmf.str[0], sizeof(kmf.str), "%.2fKM", (total_distance_m / 1000.0));
        return kmf;
}

// --- 5. Effizienz (mAh pro km) ---
msp_rendor_mAh_per_km_t construct_rendor_mAh_per_km(const battery_status_s &bat)
{
        msp_rendor_mAh_per_km_t eff{};
        eff.screenYPosition = 0x0A;
        eff.screenXPosition = 0x02;

        double dist_km = total_distance_m / 1000.0;
        if (dist_km > 0.1) { // Division durch Null verhindern, erst ab 100m anzeigen
                double mah_km = double(bat.discharged_mah) / double(dist_km);
                snprintf(&eff.str[0], sizeof(eff.str), "%.0f\x07/KM", mah_km);
        } else {
                snprintf(&eff.str[0], sizeof(eff.str), "%.0f\x07/KM", 0.0);
        }
        return eff;
}

// --- 6. Flugzeituhr (Armed Timer) ---
msp_rendor_armed_timer_t construct_rendor_armed_timer(const vehicle_status_s &status)
{
        msp_rendor_armed_timer_t timer{};
        timer.screenYPosition = 0x0F;
        timer.screenXPosition = 0x29;

        static uint64_t armed_start_time = 0;
        static uint32_t flown_seconds = 0;

        if (status.arming_state == vehicle_status_s::ARMING_STATE_ARMED) {
                if (armed_start_time == 0) {
                        armed_start_time = hrt_absolute_time(); // Startzeitpunkt merken
                }
                flown_seconds = (hrt_absolute_time() - armed_start_time) / 1000000ULL;
        } else {
                // Wenn disarmt, stoppt die Uhr, behält aber den letzten Wert
                armed_start_time = 0;
        }

        uint32_t mins = flown_seconds / 60;
        uint32_t secs = flown_seconds % 60;

        snprintf(&timer.str[0], sizeof(timer.str), "%02u:%02u", uint16_t(mins), uint16_t(secs));
        return timer;
}


// --- 9. Scrolling Compass Bar (Mit Betaflight Icons) ---
msp_rendor_compass_bar_t construct_rendor_compass_bar(const vehicle_attitude_s &att)
{
        msp_rendor_compass_bar_t bar{};
        bar.screenYPosition = 0x01; // Meistens ganz oben
        bar.screenXPosition = 0x14; // Schön mittig

        #define _N  "\x18"
        #define _E  "\x1A"
        #define _S  "\x19"
        #define _W  "\x1B"
        #define _M  "\x1C"
        #define _T  "\x1D"

        #define COMPASS_CIRCLE \
            _N _T _T _T _M _T _T _T \
            _E _T _T _T _M _T _T _T \
            _S _T _T _T _M _T _T _T \
            _W _T _T _T _M _T _T _T

        const char ribbon[] = COMPASS_CIRCLE COMPASS_CIRCLE COMPASS_CIRCLE;

        matrix::Eulerf euler(matrix::Quatf(att.q));
        double yaw_deg = (double)math::degrees(euler.psi());

        if (yaw_deg < 0.0) {
                yaw_deg += 360.0;
        }

        int index = (int)((yaw_deg + 5.625) / 11.25);
        index = index % 32;

        int center_pos = index + 32;

        // Der Kombi-Trick: "%.13s" für die Icons, dann ein Leerzeichen, dann "%03.0f" für die Zahl
        snprintf(&bar.str[0], sizeof(bar.str), "%.13s %03.0f", &ribbon[center_pos - 6], yaw_deg);

        return bar;
}

// --- Throttle in % ---
msp_rendor_throttle_t construct_rendor_throttle(const manual_control_setpoint_s &manual_control)
{
    msp_rendor_throttle_t msg{};
    msg.screenYPosition = 0x0B; // Zeile anpassen
    msg.screenXPosition = 0x02;

    // PX4 Throttle geht von -1 (unten) bis 1 (oben)
    float throttle_percent = (manual_control.throttle + 1.0f) * 50.0f;

    if (throttle_percent < 0.0f) throttle_percent = 0.0f;
    if (throttle_percent > 100.0f) throttle_percent = 100.0f;

    snprintf(&msg.str[0], sizeof(msg.str), "%3.0f%%", (double)throttle_percent);
    return msg;
}

// --- Realer Motor-Output (Average) ---
msp_rendor_motor_output_t construct_rendor_motor_output(const manual_control_setpoint_s &manual_control)
{
    msp_rendor_motor_output_t msg{};
    msg.screenYPosition = 0x0C;
    msg.screenXPosition = 0x02;

    // Umrechnung von -1.0 (Knüppel unten) auf 1.0 (Knüppel oben) zu 0 - 100%
    float throttle_percent = (manual_control.throttle + 1.0f) * 50.0f;

    // Clipping für Sicherheit (falls leichte Kalibrierungs-Ungenauigkeiten bestehen)
    if (throttle_percent < 0.0f) throttle_percent = 0.0f;
    if (throttle_percent > 100.0f) throttle_percent = 100.0f;

    // Wieder der %%-Trick für das OSD
    snprintf(&msg.str[0], sizeof(msg.str), "%3.0f%%", (double)throttle_percent);
    return msg;
}


msp_rendor_pitch_t  construct_rendor_PITCH(const vehicle_attitude_s &vehicle_attitude)
{
	// initialize results
	msp_rendor_pitch_t pit{};

	pit.screenYPosition = 0x0D;
	pit.screenXPosition = 0x02;

	// convert from quaternion to RPY
	matrix::Eulerf euler_attitude(matrix::Quatf(vehicle_attitude.q));
	double pitch_deg = (double)math::degrees(euler_attitude.theta());
	// attitude.roll = math::degrees(euler_attitude.phi()) * 10;

	memset(&pit.str[0], 0, sizeof(pit.str));
	snprintf(&pit.str[0], sizeof(pit.str), "%.1f", pitch_deg);

	return pit;
}

msp_rendor_roll_t  construct_rendor_ROLL(const vehicle_attitude_s &vehicle_attitude)
{
	// initialize results
	msp_rendor_roll_t roll{};

	roll.screenYPosition = 0x0E;
	roll.screenXPosition = 0x02;

	// convert from quaternion to RPY
	matrix::Eulerf euler_attitude(matrix::Quatf(vehicle_attitude.q));
	// double pitch = (double)math::degrees(euler_attitude.theta());
	double roll_deg = (double)math::degrees(euler_attitude.phi());

	memset(&roll.str[0], 0, sizeof(roll.str));
	snprintf(&roll.str[0], sizeof(roll.str), "%.1f", roll_deg);

	return roll;
}


msp_rendor_altitude_t construct_Rendor_ALTITUDE(const sensor_gps_s &vehicle_gps_position,
		const vehicle_local_position_s &vehicle_local_position)
{
	msp_rendor_altitude_t altitude{};

	altitude.screenYPosition = 0x03;
	altitude.screenXPosition = 0x13;

	double alt;

	// if (vehicle_gps_position.fix_type >= 2) {
	// 	// Ersetze altitude_msl_m durch (alt * 1e-3)
	// 	alt = (double)vehicle_gps_position.alt / 1000.0; // mm zu Meter konvertieren
	// } else {
	// 	alt = (double)(vehicle_local_position.z * -1.0f);
	// }
        //allways use local_position.z, which is relative to the takeoff point and thus more meaningful for den OSD user.
        alt = (double)(vehicle_local_position.z * -1.0f);

	memset(&altitude.str[0], 0, sizeof(altitude.str));
	snprintf(&altitude.str[0], sizeof(altitude.str), "%.1f\x0C", alt);

	return altitude;
}

msp_rc_t construct_MSP_RC(const input_rc_s &input_rc)
{
	// initialize result
	msp_rc_t rc;

	rc.channelValue[0] = input_rc.values[0]; // roll
	rc.channelValue[1] = input_rc.values[1]; // pitch
	rc.channelValue[2] = input_rc.values[3]; // yaw
	rc.channelValue[3] = input_rc.values[2]; // Throttle
	return rc;
}

msp_status_t construct_MSP_STATUS(const vehicle_status_s &vehicle_status)
{
	// initialize result
	msp_status_t status{0};

	if (vehicle_status.arming_state == vehicle_status_s::ARMING_STATE_ARMED) {
		status.flightModeFlags |= (1 << MSP_MODE_ARM);
	}

	return status;
}



} // namespace msp_osd
