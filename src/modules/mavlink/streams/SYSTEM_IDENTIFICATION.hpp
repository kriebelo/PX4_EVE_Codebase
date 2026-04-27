/****************************************************************************
 *
 *   Copyright (c) 2020 PX4 Development Team. All rights reserved.
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

#ifndef SYSTEM_IDENTIFICATION_HPP
#define SYSTEM_IDENTIFICATION_HPP

#include <uORB/Subscription.hpp>
#include <uORB/topics/system_identification.h>

class MavlinkStreamSystemIdentification : public MavlinkStream
{
public:
    static MavlinkStream *new_instance(Mavlink *mavlink) {
        return new MavlinkStreamSystemIdentification(mavlink);
    }

    static constexpr const char *get_name_static() { return "SYSTEM_IDENTIFICATION"; }
    static constexpr uint16_t get_id_static() { return MAVLINK_MSG_ID_SYSTEM_IDENTIFICATION; }

    const char *get_name() const override { return get_name_static(); }
    uint16_t get_id() override { return get_id_static(); }

    unsigned get_size() override
    {
        return _sys_id_sub.advertised() ? MAVLINK_MSG_ID_SYSTEM_IDENTIFICATION_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES : 0;
    }

private:
    explicit MavlinkStreamSystemIdentification(Mavlink *mavlink) : MavlinkStream(mavlink) {}

    uORB::Subscription _sys_id_sub{ORB_ID(system_identification)};

    bool send() override
    {
        system_identification_s sys_id;

        // Check if there is new data on the uORB topic
        if (_sys_id_sub.update(&sys_id)) {
            mavlink_system_identification_t msg{};

            // Map uORB fields to MAVLink fields
            msg.time_usec = sys_id.timestamp;
            msg.activation_flag = sys_id.activation_flag;
            msg.mode_selector = sys_id.mode_selector;
            msg.aileron = sys_id.aileron;
            msg.elevator = sys_id.elevator;
            msg.rudder = sys_id.rudder;
            msg.throttle = sys_id.throttle;
            msg.roll_rate = sys_id.roll_rate;
            msg.pitch_rate = sys_id.pitch_rate;
            msg.yaw_rate = sys_id.yaw_rate;
            msg.roll_angle = sys_id.roll_angle;
            msg.pitch_angle = sys_id.pitch_angle;
            msg.airspeed = sys_id.airspeed;

            // Send the MAVLink message
            mavlink_msg_system_identification_send_struct(_mavlink->get_channel(), &msg);

            return true;
        }

        return false;
    }
};

#endif // SYSTEM_IDENTIFICATION_HPP
