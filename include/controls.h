#include "vex.h"

// chassis
void move_chassis(float left, float right);
float curve(float i, float scale);

// intake
void move_intake(float volts);

// lift
void move_lift(float position, float vel);
void lift_reset();
void lift_grab();
void lift_score();

// mogo / doinker
void mogo_control();
void doinker_control();

void controls();