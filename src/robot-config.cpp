#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain Brain;
controller controller1;

//The motor constructor takes motors as (port, ratio, reverse), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

//Add your devices below, and don't forget to do the same in robot-config.h:
#define RED ratio36_1
#define GREEN ratio18_1
#define BLUE ratio6_1

#define REVERSE_L true
#define REVERSE_R false
#define REVERSE_INTAKE false
#define REVERSE_LIFT false // change later

#define PORT_LF PORT4
#define PORT_LM PORT5
#define PORT_LB PORT6
#define PORT_RF PORT7
#define PORT_RM PORT8
#define PORT_RB PORT9
#define PORT_INTAKE PORT10
#define PORT_LIFT PORT11

#define PORT_IMU PORT12
#define PORT_OPTICAL PORT13
#define PORT_MOGO Brain.ThreeWirePort.A
#define PORT_DOINKER Brain.ThreeWirePort.B
#define PORT_LIMIT Brain.ThreeWirePort.C

// motors/motor groups
motor lf = motor(PORT_LF, BLUE, REVERSE_L);
motor lm = motor(PORT_LM, BLUE, REVERSE_L);
motor lb = motor(PORT_LB, BLUE, REVERSE_L);
motor rf = motor(PORT_RF, BLUE, REVERSE_R);
motor rm = motor(PORT_RM, BLUE, REVERSE_R);
motor rb = motor(PORT_RB, BLUE, REVERSE_R);
motor intake = motor(PORT_INTAKE, BLUE, REVERSE_INTAKE);
motor lift = motor(PORT_LIFT, GREEN, REVERSE_LIFT);
motor_group l = motor_group(lf, lm, lb);
motor_group r = motor_group(rf, rm, rb);

// sensors/pneumatics
inertial imu = inertial(PORT_IMU);
optical optic = optical(PORT_OPTICAL);
digital_out mogo = digital_out(PORT_MOGO);
digital_out doinker = digital_out(PORT_DOINKER);
limit limit_switch = limit(PORT_LIMIT);

void vexcodeInit( void ) {
  // nothing to initialize
}