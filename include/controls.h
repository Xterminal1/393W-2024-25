#include "vex.h"

// chassis control
void move_chassis(float left, float right);
float curve(float x, float scale);
void arcade(float forward, float turn);
void arcade(float forward, float turn, bool enable_turn_curve);

// color filters
void filter_ring(int intake_time);
void filter_color(std::string sorted_color);
void detect_ring();
void detect_and_stop_ring();
void filter_red();
void filter_blue();

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

#define TURN_CURVE_SCALE 15

// color settings
#define BLUE_LOWER_LIM 210
#define BLUE_UPPER_LIM 230
#define RED_LOWER_LIM 8
#define RED_UPPER_LIM 15

#define LIFT_VEL 100
#define LIFT_GRAB_POS 90
#define LIFT_SCORE_POS 450