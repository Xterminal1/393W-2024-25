#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

// constant: 47.0119216518, starti: 40, max_integral: 14.5
// Converting encoder units to inches: https://www.desmos.com/calculator/5xmwm3qp4b
// Calculating Euclidean distances: https://www.desmos.com/calculator/mh9umhcuo3

void default_constants() {
  // PID gains
  chassis.set_drive_constants(DRIVE_MAX, DRIVE_KP, DRIVE_KI, DRIVE_KD, DRIVE_STARTI);  
  chassis.set_heading_constants(HEADING_MAX, HEADING_KP, HEADING_KI, HEADING_KD, HEADING_STARTI);
  chassis.set_turn_constants(TURN_MAX, TURN_KP, TURN_KI, TURN_KD, TURN_STARTI);
  chassis.set_swing_constants(SWING_MAX, SWING_KP, SWING_KI, SWING_KD, SWING_STARTI);

  // exit conditions
  chassis.set_drive_exit_conditions(DRIVE_SETTLE_ERROR, DRIVE_SETTLE_TIME, DRIVE_TIMEOUT);
  chassis.set_turn_exit_conditions(TURN_SETTLE_ERROR, TURN_SETTLE_TIME, TURN_TIMEOUT);
  chassis.set_swing_exit_conditions(SWING_SETTLE_ERROR, SWING_SETTLE_TIME, SWING_TIMEOUT);
}

void arcs() { chassis.set_heading_constants(ARC_MAX, ARC_KP, ARC_KI, ARC_KD, ARC_STARTI); }
void correction() { chassis.set_heading_constants(HEADING_MAX, HEADING_KP, HEADING_KI, HEADING_KD, HEADING_STARTI); }

void redLeft() {
  thread t = thread(filter_blue);

  // mogo 1 clamp
  chassis.drive_distance(-19); // drive -> mogo
  chassis.turn_to_angle(27);
  chassis.drive_distance(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  move_intake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // rings 1 & 2
  chassis.turn_to_angle(149);
  chassis.drive_distance(23);
  wait(500, msec);

  // ring 3
  chassis.drive_distance(-5);
  chassis.turn_to_angle(130);
  chassis.drive_distance(8.5);
  wait(500, msec);

  // ring 4
  chassis.drive_distance(-20);
  wait(500, msec);
  arcs(); // enable arc turns
  chassis.drive_distance(22.5, 29);

  // chassis.turn_kd = 8;
  // chassis.drive_max_voltage = 6;
  // chassis.turn_to_angle(147); // turn -> ring 2
  // chassis.turn_kd = 7; 
  // move_intake(12);
  // wait(200, msec);
  // chassis.drive_distance(30); // drive -> ring 2
  // wait(600, msec);

  // // ring 3
  // chassis.drive_distance(-8); // drive bwd -> align w/ ring 3
  // chassis.drive_max_voltage = 8;
  // chassis.turn_to_angle(126); // turn -> ring 3
  // chassis.drive_distance(12); // drive -> ring 3
  // chassis.drive_max_voltage = 10;
  // wait(500, msec);

  // // ring 4
  // chassis.drive_distance(-20); // drive bwd -> align w/ ring 4
  // wait(1500, msec);
  // arcs(); // enable arc turns
  // chassis.drive_distance(30, 29); // swing -> intake ring 4
  // wait(800, msec);

  // // ladder touch
  // //chassis.drive_distance(-23, 88); // drive -> ladder
  // chassis.turn_to_angle(-115); // turn -> ladder
  // chassis.drive_distance(40); // drive -> ladder
  // wait(200, msec);
  // l.stop();
  // r.stop();
}

void blueRight() {
  thread t = thread(filter_red);

  // mogo 1 clamp
  chassis.drive_distance(-19); // drive -> mogo
  wait(10, msec);
  mogo.set(true); // clamp mogo

  // rings 1 & 2
  chassis.turn_kd = 8;
  chassis.drive_max_voltage = 6;
  chassis.turn_to_angle(-147); // turn -> ring 2
  chassis.turn_kd = 7; 
  move_intake(12);
  wait(200, msec);
  chassis.drive_distance(30); // drive -> ring 2
  wait(600, msec);

  // ring 3
  chassis.drive_distance(-8); // drive bwd -> align w/ ring 3
  chassis.drive_max_voltage = 8;
  chassis.turn_to_angle(-126); // turn -> ring 3
  chassis.drive_distance(12); // drive -> ring 3
  chassis.drive_max_voltage = 10;
  wait(500, msec);  

  // ring 4
  chassis.drive_distance(-20); // drive bwd -> align w/ ring 4
  wait(1000, msec);
  arcs(); // enable arc turns
  chassis.drive_distance(30, -29); // swing -> intake ring 4
  wait(800, msec);

  // ladder touch
  chassis.turn_to_angle(115); // turn -> ladder
  chassis.drive_distance(40); // drive -> ladder
  wait(200, msec);
  l.stop();
  r.stop();
}

void redRight() {
  thread t = thread(filter_blue);

  // mogo 1 clamp
  chassis.drive_distance(-26.5);
  chassis.drive_max_voltage = 9;
  chassis.turn_to_angle(-28);
  chassis.drive_distance(-20.5);
  mogo.set(true);
  chassis.drive_max_voltage = 12;
  
  // preload / ring 1
  chassis.turn_to_angle(19);
  move_intake(12);
  wait(800, msec);
  
  // partially intake ring 2
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(14);
  detect_and_stop_ring();
  chassis.drive_max_voltage = 12;

  // drop mogo 1 near corner
  chassis.turn_to_angle(151);
  chassis.drive_distance(-21);
  mogo.set(false);
  wait(300, msec);
  
  // clamp mogo 2
  chassis.drive_distance(19);
  chassis.turn_to_angle(-105);//-98
  chassis.drive_distance(-15);
  mogo.set(true);

  // ladder touch
  chassis.turn_to_angle(-67);
  move_intake(12);
  wait(500, msec);
  move_intake(0);
  chassis.drive_distance(-25);
}

void blueLeft() {
  //thread colorSorting = thread(filterRed);

  // mogo 1 clamp
  chassis.drive_distance(-26.5);
  chassis.drive_max_voltage = 9;
  chassis.turn_to_angle(28);
  chassis.drive_distance(-20.5);
  mogo.set(true);
  chassis.drive_max_voltage = 12;
  
  // preload / ring 1
  chassis.turn_to_angle(-19);
  move_intake(12);
  wait(800, msec);

  // partially intake ring 2
  chassis.drive_max_voltage = 6;
  chassis.drive_distance(14);
  detect_and_stop_ring();
  chassis.drive_max_voltage = 12;

  // drop mogo 1 near corner
  chassis.turn_to_angle(-151);
  chassis.drive_distance(-21);
  mogo.set(false);
  wait(300, msec);

  // clamp mogo 2
  chassis.drive_distance(19);
  chassis.turn_to_angle(98);
  chassis.drive_distance(-15);
  mogo.set(true);

  // ladder touch
  chassis.turn_to_angle(67);
  move_intake(12);
  wait(500, msec);
  move_intake(0);
  chassis.drive_distance(-25);
}

void skills() {
  int intake_time = 350;
  // chassis.drive_kp = 0.8;
  // chassis.drive_ki = 0.03;
  // chassis.drive_kd = 5;
  // chassis.turn_kp = 0.8;
  // chassis.turn_ki = 0;
  // chassis.turn_kd = 7;
  //chassis.turn_kd = 8;
  chassis.turn_max_voltage = 9;

  // alliance stake
  move_intake(12);
  wait(500, msec);

  // mogo 1 clamp
  chassis.drive_distance(13);
  move_intake(0);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-13);
  mogo.set(true);
  wait(500, msec);

  // ring 1
  move_intake(12);
  chassis.drive_max_voltage = 6;
  chassis.turn_to_angle(-25);
  chassis.drive_distance(27.5); 
  wait(1500, msec);

  // ring 2
  chassis.turn_to_angle(-90);
  chassis.drive_distance(28);
  wait(1000, msec);

  // ring 3
  chassis.turn_to_angle(-17);
  chassis.drive_distance(29);
  wait(1500, msec);

  // ring 4
  chassis.drive_distance(-37);
  chassis.turn_to_angle(165);
  chassis.drive_distance(17);
  wait(2000, msec);

  // ring 5
  chassis.turn_to_angle(175);
  chassis.drive_distance(15);
  wait(2000, msec);

  // ring 6
  chassis.turn_to_angle(-52);
  chassis.drive_distance(14);
  wait(1000, msec);

  // mogo unclamp -> corner
  chassis.turn_to_angle(30);
  chassis.drive_distance(-8);
  mogo.set(false);
  move_intake(-12);
  wait(1000, msec);

  // mogo 2
  chassis.drive_distance(7);
  move_intake(0);
  chassis.turn_to_angle(-90);
  chassis.drive_max_voltage = 4;
  chassis.drive_distance(-71);
  mogo.set(true);
  move_intake(12);

  // ring 5
  // chassis.turn_to_angle(-173);
  // chassis.drive_distance(14.5);
  // wait(1000, msec);

  // ring 6
  // chassis.turn_to_angle(-45);
  // chassis.drive_distance(12);
  // wait(1000, msec);

  // mogo 1 unclamp -> corner
  // chassis.turn_to_angle(25);
  // wait(2000, msec);
  // chassis.drive_distance(-8);
  // mogo.set(false);
  // moveIntake(-12);

  // mogo 2 clamp
  // chassis.drive_distance(10);
  // moveIntake(0);

  // chassis.turn_to_angle(-90);
  // chassis.drive_distance(-71);
  // mogo.set(true);
  // moveIntake(12);

  // // ring 1
  // chassis.turn_to_angle(90);
  // chassis.drive_distance(29);
}

void test() {
  //drive_test();
  //turn_test();
  //swing_test();
  //full_test();
  move_intake(12);
  detect_ring();

  chassis.turn_to_angle(90);
  move_intake(12);

  chassis.turn_to_angle(180);
  detect_ring();

  chassis.turn_to_angle(-90);
  detect_ring();

  chassis.turn_to_angle(0);
  detect_ring();
}

void red_left() {
  // preload -> alliance stake
  lift_grab();
  move_intake(12);
  wait(500, msec);
  chassis.turn_to_angle(-50);
  move_intake(0);
  chassis.drive_distance(4.5);
  move_lift(620, 100);
  wait(500, msec);

  // clamp mogo
  chassis.drive_max_voltage = 6;
  chassis.turn_to_angle(-19);
  //thread wc = thread(wait_and_clamp);
  chassis.drive_distance(-32);
  thread liftReset = thread(lift_reset);
  mogo.set(true);
  wait(500, msec);
  move_intake(12);

  // // ring 2
  //chassis.turn_max_voltage = 12;
  chassis.drive_max_voltage = 10;
  chassis.turn_to_angle(135);
  //chassis.turn_max_voltage = 12;
  chassis.drive_distance(22.5);

  // ring 3
  chassis.drive_distance(-8); // drive bwd -> align w/ ring 3
  //chassis.drive_max_voltage = 8;
  chassis.turn_to_angle(120); // turn -> ring 3
  chassis.drive_distance(11.5); // drive -> ring 3
  //chassis.drive_max_voltage = 10;
  wait(500, msec);

  // ring 4
  chassis.drive_distance(-17); // drive bwd -> align w/ ring 4
  chassis.set_heading_constants(ARC_MAX, ARC_KP, ARC_KI, ARC_KD, ARC_STARTI); // enable arc turns
  chassis.drive_distance(31, 33); // swing -> intake ring 4
  //wait(500, msec);

  // ladder touch
  //chassis.drive_distance(-23, 88); // drive -> ladder
  chassis.turn_to_angle(-115); // turn -> ladder
  //thread liftx = thread(lift_score);
  chassis.drive_distance(40); // drive -> ladder
  wait(200, msec);
  l.stop();
  r.stop();
}

void blue_right() {
// preload -> alliance stake
  // lift_grab();
  // move_intake(12);
  // wait(500, msec);
  // chassis.turn_to_angle(50);
  // move_intake(0);
  // chassis.drive_distance(4.5);
  // move_lift(620, 100);
  // wait(500, msec);

  // // clamp mogo
  // thread liftReset = thread(lift_reset);
  // chassis.drive_max_voltage = 6;
  // chassis.turn_to_angle(19);
  // //thread wc = thread(wait_and_clamp);
  // chassis.drive_distance(-32);
  // mogo.set(true);
  // wait(500, msec);
  // move_intake(12);

  // // // ring 2
  // chassis.turn_max_voltage = 12;
  // chassis.drive_max_voltage = 6;
  // chassis.turn_to_angle(-135);
  // chassis.turn_max_voltage = 12;
  // chassis.drive_distance(22.5);

  // // ring 3
  // chassis.drive_distance(-8); // drive bwd -> align w/ ring 3
  // chassis.drive_max_voltage = 8;
  // chassis.turn_to_angle(-126); // turn -> ring 3
  // chassis.drive_distance(12); // drive -> ring 3
  // chassis.drive_max_voltage = 10;
  // wait(500, msec);

  // // ring 4
  // chassis.drive_distance(-20); // drive bwd -> align w/ ring 4
  // chassis.set_heading_constants(ARC_MAX, ARC_KP, ARC_KI, ARC_KD, ARC_STARTI); // enable arc turns
  // chassis.drive_distance(31, -50); // swing -> intake ring 4
  // //wait(500, msec);

  // // ladder touch
  // //chassis.drive_distance(-23, 88); // drive -> ladder
  // chassis.turn_to_angle(128); // turn -> ladder
  // //thread liftx = thread(lift_score);
  // chassis.drive_distance(40); // drive -> ladder
  // wait(200, msec);
  // l.stop();
  // r.stop();

  thread t = thread(filter_red);

  // mogo 1 clamp
  chassis.drive_distance(-19); // drive -> mogo
  chassis.turn_to_angle(-27);
  chassis.drive_distance(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  move_intake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // rings 1 & 2
  chassis.turn_to_angle(-149);
  chassis.drive_distance(23);
  wait(500, msec);

  // ring 3
  chassis.drive_distance(-5);
  chassis.turn_to_angle(-130);
  chassis.drive_distance(8.5);
  wait(500, msec);

  // ring 4
  chassis.drive_distance(-20);
  wait(500, msec);
  arcs(); // enable arc turns
  chassis.drive_distance(22.5, -29);
}

void red_right() {
  thread t = thread(filter_blue);

  // mogo 1 clamp
  chassis.drive_distance(-19); // drive -> mogo
  chassis.turn_to_angle(-27);
  chassis.drive_distance(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  move_intake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // ring 2
  chassis.turn_to_angle(-113.5);
  chassis.drive_distance(20);
  wait(1000, msec);

  // ladder touch
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-51.5);
  chassis.drive_distance(-30);
}

void blue_left() {
  thread t = thread(filter_red);

  // mogo 1 clamp
  chassis.drive_distance(-19); // drive -> mogo
  chassis.drive_max_voltage = 6;
  chassis.turn_to_angle(27);
  chassis.drive_distance(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  move_intake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // ring 2
  chassis.turn_to_angle(110);
  chassis.drive_distance(20);
  wait(1000, msec);

  // ladder touch
  chassis.drive_distance(-18);
  chassis.turn_to_angle(51.5);
  wait(1000, msec);
  chassis.drive_distance(-30);
  wait(200, msec);
  l.stop();
  r.stop();
}

#pragma region