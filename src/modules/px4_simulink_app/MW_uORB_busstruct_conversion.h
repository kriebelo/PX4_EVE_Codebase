#ifndef _MW_UORB_BUSSTRUCT_CONVERSION_H_
#define _MW_UORB_BUSSTRUCT_CONVERSION_H_

#include <uORB/topics/airspeed.h>
#include <uORB/topics/input_rc.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/vehicle_odometry.h>

typedef struct airspeed_s  px4_Bus_airspeed ;
typedef struct input_rc_s  px4_Bus_input_rc ;
typedef struct sensor_accel_s  px4_Bus_sensor_accel ;
typedef struct sensor_gyro_s  px4_Bus_sensor_gyro ;
typedef struct vehicle_odometry_s  px4_Bus_vehicle_odometry ;

#endif
