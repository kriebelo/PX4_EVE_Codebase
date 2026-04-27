#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/airspeed.h>
#include <uORB/topics/flight_testing.h>
#include <uORB/topics/glide_controller.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/system_identification.h>
#include <uORB/topics/vehicle_odometry.h>

typedef struct airspeed_s  px4_Bus_airspeed ;
typedef struct flight_testing_s  px4_Bus_flight_testing ;
typedef struct glide_controller_s  px4_Bus_glide_controller ;
typedef struct input_rc_s  px4_Bus_input_rc ;
typedef struct sensor_accel_s  px4_Bus_sensor_accel ;
typedef struct sensor_gyro_s  px4_Bus_sensor_gyro ;
typedef struct system_identification_s  px4_Bus_system_identification ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;

#endif
