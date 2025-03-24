#include "vex.h"

using namespace vex;

brain Brain;
controller controller1;

#define RED ratio36_1
#define GREEN ratio18_1
#define BLUE ratio6_1

#define DIR_L true
#define DIR_R false
#define DIR_INTAKE false
#define DIR_LIFT true

#define _LF PORT14
#define _LM PORT15
#define _LB PORT17
#define _RF PORT11
#define _RM PORT12
#define _RB PORT13
#define _INTAKE PORT10
#define _LIFT PORT9

#define _IMU PORT18
#define _OPTICAL PORT20
#define _ROTATION PORT8
#define _MOGO Brain.ThreeWirePort.A
#define _DOINK Brain.ThreeWirePort.B
#define _INTAKE_PISTON Brain.ThreeWirePort.C

// motors/motor groups
motor lf = motor(_LF, BLUE, DIR_L);
motor lm = motor(_LM, BLUE, DIR_L);
motor lb = motor(_LB, BLUE, DIR_L);
motor rf = motor(_RF, BLUE, DIR_R);
motor rm = motor(_RM, BLUE, DIR_R);
motor rb = motor(_RB, BLUE, DIR_R);
motor intake = motor(_INTAKE, BLUE, DIR_INTAKE);
motor lift = motor(_LIFT, GREEN, DIR_LIFT);
motor_group l = motor_group(lf, lm, lb);
motor_group r = motor_group(rf, rm, rb);

// sensors
inertial imu = inertial(_IMU);
optical opticalSensor = optical(_OPTICAL);
rotation rotationSensor = rotation(_ROTATION, false);

// pneumatics
digital_out mogo = digital_out(_MOGO);
digital_out doink = digital_out(_DOINK);
digital_out intakePiston = digital_out(_INTAKE_PISTON);

// JAR-Template Config                         

Drive chassis(
    // drive setup
    ZERO_TRACKER_NO_ODOM, 
    motor_group(lf, lm, lb), // left mtrs
    motor_group(rf, rm, rb), // right mtrs
    _IMU, // IMU port
    3.25, // wheel diameter [inches]
    0.75, // external drive gear ratio
    360, // gyro scale

    // holonomic drive setup
    PORT1, // LF
    -PORT2, // RF
    PORT3, // LB
    -PORT4, // RB
    
    // position tracking setup
    3, // forward tracker port
    2.75, // forward tracker diameter
    -2, // forward tracker center distance
    1, // sideways tracker port
    -2.75, // sideways tracker diameter
    5.5 // sideways tracker center distance
);

void vexcodeInit( void ) {
  // nothing to initialize
}