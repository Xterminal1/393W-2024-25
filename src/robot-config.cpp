#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain Brain;
controller Controller;

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

#define PORT_LF PORT1
#define PORT_LM PORT2
#define PORT_LB PORT3
#define PORT_RF PORT4
#define PORT_RM PORT5
#define PORT_RB PORT6
#define PORT_INTAKE PORT7
#define PORT_LIFT PORT8

#define PORT_IMU PORT9
#define PORT_OPTICAL PORT10
#define PORT_MOGO A
#define PORT_DOINKER B
#define PORT_LIMIT C

// motors/motor groups
motor lf = motor(PORT_LF, BLUE, REVERSE_L);
motor lm = motor(PORT_LM, BLUE, REVERSE_L);
motor lb = motor(PORT_LB, BLUE, REVERSE_L);
motor rf = motor(PORT_RF, BLUE, REVERSE_R);
motor rm = motor(PORT_RM, BLUE, REVERSE_R);
motor rb = motor(PORT_RB, BLUE, REVERSE_R);
motor intake = motor(PORT_INTAKE, BLUE, REVERSE_INTAKE);
motor lift = motor(PORT_LIFT, BLUE, REVERSE_LIFT);
motor_group l = motor_group(lf, lm, lb);
motor_group r = motor_group(rf, rm, rb);

// sensors/pneumatics
inertial imu = inertial(PORT_IMU);
optical optic = optical(PORT_OPTICAL);
digital_out mogo = digital_out(Brain.ThreeWirePort.PORT_MOGO);
digital_out doinker = digital_out(Brain.ThreeWirePort.PORT_DOINKER);
limit limit_switch = limit(Brain.ThreeWirePort.PORT_LIMIT);

// motor LF = motor(PORT9, ratio6_1, true);
// motor LM = motor(PORT2, ratio6_1, true);
// motor LB = motor(PORT11, ratio6_1, true);
// motor RF = motor(PORT6, ratio6_1, false);
// motor RM = motor(PORT5, ratio6_1, false);
// motor RB = motor(PORT4, ratio6_1, false);

// motor intake_1 = motor(PORT7, ratio6_1, false);
// motor intake_2 = motor(PORT8, ratio6_1, false);

// inertial imu = inertial(PORT9);
// digital_out mogo = digital_out(Brain.ThreeWirePort.A);
// digital_out doinker = digital_out(Brain.ThreeWirePort.B);
// limit limit_switch = limit(Brain.ThreeWirePort.C);

// motor_group L = motor_group(LF, LM, LB);
// motor_group R = motor_group(RF, RM, RB);
// motor_group intake = motor_group(intake_1, intake_2);

void vexcodeInit( void ) {
  // nothing to initialize
}