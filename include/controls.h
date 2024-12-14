#include "vex.h"

// chassis control
void moveChassis(float left, float right);
float curve(float x, float scale);
void arcade(float forward, float turn);
void arcade(float forward, float turn, bool enableTurnCurve);

// color filters
void filterRing(int intakeTime);
void filterColor(string sortedColor);
void detectRing();
void detectStopRing();
void filterRed();
void filterBlue();

// intake
void moveIntake(float volts);

// lift
void moveLift(float position, float vel);
void liftReset();
void liftGrab();
void liftScore();

// mogo / doinker
void mogoControl();
void doinkerControl();

void controls();

#define TURN_CURVE_SCALE 15
#define LIFT_VEL 100
#define LIFT_GRAB_POS 90
#define LIFT_SCORE_POS 450