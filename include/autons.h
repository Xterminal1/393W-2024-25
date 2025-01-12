#pragma once
#include "JAR-Template/drive.h"

class Drive;
extern Drive chassis;
void default_constants();

// autons
void red_right();
void blue_left();
void red_left();
void blue_right();
void redLeft();
void redRight();
void blueRight();
void blueLeft();
void skills();
void test();

// PID gains
// lateral PID controller
#define DRIVE_MAX 12
#define DRIVE_KP 1.2
#define DRIVE_KI 0.02
#define DRIVE_KD 8
#define DRIVE_STARTI 0
#define DRIVE_SETTLE_ERROR 1.5
#define DRIVE_SETTLE_TIME 300
#define DRIVE_TIMEOUT 4000

// heading PID controller
#define HEADING_MAX 6
#define HEADING_KP 0.1
#define HEADING_KI 0
#define HEADING_KD 0
#define HEADING_STARTI 0

// angular PID controller
#define TURN_MAX 12
#define TURN_KP 0.6
#define TURN_KI 0
#define TURN_KD 4
#define TURN_STARTI 15
#define TURN_SETTLE_ERROR 1
#define TURN_SETTLE_TIME 300
#define TURN_TIMEOUT 1000

// swing PID controller
#define SWING_MAX 12
#define SWING_KP 1
#define SWING_KI 0.01
#define SWING_KD 6
#define SWING_STARTI 15
#define SWING_SETTLE_ERROR 1
#define SWING_SETTLE_TIME 200
#define SWING_TIMEOUT 3000

// arc PID controller
#define ARC_MAX 10
#define ARC_KP 0.6
#define ARC_KI 0.001
#define ARC_KD 3
#define ARC_STARTI 0