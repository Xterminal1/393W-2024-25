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

// void move10() {chassis.move(25, 5.5); }

// void waitDetect() {detect_ring3();}

// void extras() {
//   waitDetect();
//   wait(15, msec);
//   lift_grab();
// }

// void runit() {
//   thread m10 = thread(move10);
//   extras();
//   // waitDetect();
//   // wait(200, msec);
//   // lift_grab();
//   //moveIntake(0);
// }

// void redLeft() {
//   thread abdal = thread(filter_blue);
  
//   chassis.turn_kd = 3.8;
//   chassis.drive_settle_error = 0.5;
//   chassis.drive_settle_time = 100;
//   chassis.turn_settle_time = 150;
//   intake.setMaxTorque(100, percent);

//   // mogo 1 clamp
//   chassis.move(-19); // drive -> mogo
//   chassis.turn(27);
//   chassis.move(-6);
//   mogo.set(true); // clamp mogo
//   moveIntake(12);
//   wait(300, msec);

//   // rings 1 & 2
//   chassis.turn(149);
//   chassis.move(23);
//   //wait(500, msec);

//   // ring 3
//   chassis.move(-5);
//   chassis.turn(130);
//   chassis.move(8.5);
//   //wait(500, msec);

//   // ring 4
//   chassis.move(-20);
//   //wait(500, msec);
//   arcs(); // enable arc turns
//   chassis.arc(18, 50);//22.5,29

//   // ring 5 -> ally stake
//   chassis.turn(-57);
//   chassis.move(38);
//   runit();
//   // turn 300
//   // driv

//   // LADDER TOUCH
//   // chassis.turn(-107);
//   // chassis.move(42);

//   // chassis.turn_kd = 8;
//   // chassis.drive_max_voltage = 6;
//   // chassis.turn_to_angle(147); // turn -> ring 2
//   // chassis.turn_kd = 7; 
//   // moveIntake(12);
//   // wait(200, msec);
//   // chassis.drive_distance(30); // drive -> ring 2
//   // wait(600, msec);

//   // // ring 3
//   // chassis.drive_distance(-8); // drive bwd -> align w/ ring 3
//   // chassis.drive_max_voltage = 8;
//   // chassis.turn_to_angle(126); // turn -> ring 3
//   // chassis.drive_distance(12); // drive -> ring 3
//   // chassis.drive_max_voltage = 10;
//   // wait(500, msec);

//   // // ring 4
//   // chassis.drive_distance(-20); // drive bwd -> align w/ ring 4
//   // wait(1500, msec);
//   // arcs(); // enable arc turns
//   // chassis.drive_distance(30, 29); // swing -> intake ring 4
//   // wait(800, msec);

//   // // ladder touch
//   // //chassis.drive_distance(-23, 88); // drive -> ladder
//   // chassis.turn_to_angle(-115); // turn -> ladder
//   // chassis.drive_distance(40); // drive -> ladder
//   // wait(200, msec);
//   // l.stop();
//   // r.stop();
// }

void blueRight2() {
  thread t = thread(filterRed);

  // mogo 1 clamp
  chassis.move(-19); // drive -> mogo
  wait(10, msec);
  mogo.set(true); // clamp mogo

  // rings 1 & 2
  chassis.turn_kd = 8;
  chassis.drive_max_voltage = 6;
  chassis.move(-147); // turn -> ring 2
  chassis.turn_kd = 7; 
  moveIntake(12);
  wait(200, msec);
  chassis.move(30); // drive -> ring 2
  wait(600, msec);

  // ring 3
  chassis.move(-8); // drive bwd -> align w/ ring 3
  chassis.drive_max_voltage = 8;
  chassis.turn(-126); // turn -> ring 3
  chassis.move(12); // drive -> ring 3
  chassis.drive_max_voltage = 10;
  wait(500, msec);  

  // ring 4
  chassis.move(-20); // drive bwd -> align w/ ring 4
  wait(1000, msec);
  arcs(); // enable arc turns
  chassis.arc(30, -29); // swing -> intake ring 4
  wait(800, msec);

  // ladder touch
  chassis.turn(115); // turn -> ladder
  chassis.move(40); // drive -> ladder
  wait(200, msec);
  l.stop();
  r.stop();
}

void redRight() {
  thread t = thread(filterBlue);

  // mogo 1 clamp
  chassis.move(-26.5);
  chassis.turn(-28);
  chassis.move(-20.5, 9);
  mogo.set(true);
  
  // preload / ring 1
  chassis.turn(19);
  moveIntake(12);
  wait(800, msec);
  
  // partially intake ring 2
  chassis.move(14, 6);
  detectStopRing();

  // drop mogo 1 near corner
  chassis.turn(151);
  chassis.move(-21, 12);
  mogo.set(false);
  wait(300, msec);
  
  // clamp mogo 2
  chassis.move(19);
  chassis.turn(-105);//-98
  chassis.move(-15);
  mogo.set(true);

  // ladder touch
  chassis.turn(-67);
  moveIntake(12);
  wait(500, msec);
  moveIntake(0);
  chassis.move(-25);
}

void blueLeft() {
  //thread colorSorting = thread(filterRed);

  // mogo 1 clamp
  chassis.move(-26.5);
  chassis.turn(28);
  chassis.move(-20.5, 9);
  mogo.set(true);
  
  // preload / ring 1
  chassis.turn(-19);
  moveIntake(12);
  wait(800, msec);

  // partially intake ring 2
  chassis.move(14, 6);
  detectStopRing();

  // drop mogo 1 near corner
  chassis.turn(-151);
  chassis.move(-21);
  mogo.set(false);
  wait(300, msec);

  // clamp mogo 2
  chassis.move(19);
  chassis.turn(98);
  chassis.move(-15);
  mogo.set(true);

  // ladder touch
  chassis.turn(67);
  moveIntake(12);
  wait(500, msec);
  moveIntake(0);
  chassis.move(-25);
}

// void skills() {
//   int intake_time = 350;
//   // chassis.drive_kp = 0.8;
//   // chassis.drive_ki = 0.03;
//   // chassis.drive_kd = 5;
//   // chassis.turn_kp = 0.8;
//   // chassis.turn_ki = 0;
//   // chassis.turn_kd = 7;
//   //chassis.turn_kd = 8;
//   chassis.turn_max_voltage = 9;

//   // alliance stake
//   moveIntake(12);
//   wait(500, msec);

//   // mogo 1 clamp
//   chassis.drive_distance(13);
//   moveIntake(0);
//   chassis.turn_to_angle(90);
//   chassis.drive_distance(-13);
//   mogo.set(true);
//   wait(500, msec);

//   // ring 1
//   moveIntake(12);
//   chassis.drive_max_voltage = 6;
//   chassis.turn_to_angle(-25);
//   chassis.drive_distance(27.5); 
//   wait(1500, msec);

//   // ring 2
//   chassis.turn_to_angle(-90);
//   chassis.drive_distance(28);
//   wait(1000, msec);

//   // ring 3
//   chassis.turn_to_angle(-17);
//   chassis.drive_distance(29);
//   wait(1500, msec);

//   // ring 4
//   chassis.drive_distance(-37);
//   chassis.turn_to_angle(165);
//   chassis.drive_distance(17);
//   wait(2000, msec);

//   // ring 5
//   chassis.turn_to_angle(175);
//   chassis.drive_distance(15);
//   wait(2000, msec);

//   // ring 6
//   chassis.turn_to_angle(-52);
//   chassis.drive_distance(14);
//   wait(1000, msec);

//   // mogo unclamp -> corner
//   chassis.turn_to_angle(30);
//   chassis.drive_distance(-8);
//   mogo.set(false);
//   moveIntake(-12);
//   wait(1000, msec);

//   // mogo 2
//   chassis.drive_distance(7);
//   moveIntake(0);
//   chassis.turn_to_angle(-90);
//   chassis.drive_max_voltage = 4;
//   chassis.drive_distance(-71);
//   mogo.set(true);
//   moveIntake(12);

//   // ring 5
//   // chassis.turn_to_angle(-173);
//   // chassis.drive_distance(14.5);
//   // wait(1000, msec);

//   // ring 6
//   // chassis.turn_to_angle(-45);
//   // chassis.drive_distance(12);
//   // wait(1000, msec);

//   // mogo 1 unclamp -> corner
//   // chassis.turn_to_angle(25);
//   // wait(2000, msec);
//   // chassis.drive_distance(-8);
//   // mogo.set(false);
//   // moveIntake(-12);

//   // mogo 2 clamp
//   // chassis.drive_distance(10);
//   // moveIntake(0);

//   // chassis.turn_to_angle(-90);
//   // chassis.drive_distance(-71);
//   // mogo.set(true);
//   // moveIntake(12);

//   // // ring 1
//   // chassis.turn_to_angle(90);
//   // chassis.drive_distance(29);
// }

void test() {
  //drive_test();
  //turn_test();
  //swing_test();
  //full_test();
  moveIntake(12);
  detectRing();

  chassis.turn(90);
  moveIntake(12);

  chassis.turn(180);
  detectRing();

  chassis.turn(-90);
  detectRing();

  chassis.turn(0);
  detectRing();
}

void red_left() {
  // preload -> alliance stake
  lift_grab();
  moveIntake(12);
  wait(500, msec);
  chassis.turn(-50);
  moveIntake(0);
  chassis.move(4.5);
  moveLift(620, 100);
  wait(500, msec);

  // clamp mogo
  //chassis.drive_max_voltage = 6;
  chassis.turn(-19, 6);
  //thread wc = thread(wait_and_clamp);
  chassis.move(-32, 6);
  thread liftReset = thread(lift_reset);
  mogo.set(true);
  wait(500, msec);
  moveIntake(12);

  // // ring 2
  //chassis.turn_max_voltage = 12;
  //chassis.drive_max_voltage = 10;
  chassis.turn(135);
  //chassis.turn_max_voltage = 12;
  chassis.move(22.5, 10);

  // ring 3
  chassis.move(-8, 10); // drive bwd -> align w/ ring 3
  //chassis.drive_max_voltage = 8;
  chassis.turn(120); // turn -> ring 3
  chassis.move(11.5, 10); // drive -> ring 3
  //chassis.drive_max_voltage = 10;
  wait(500, msec);

  // ring 4
  chassis.move(-17, 10); // drive bwd -> align w/ ring 4
  chassis.set_heading_constants(ARC_MAX, ARC_KP, ARC_KI, ARC_KD, ARC_STARTI); // enable arc turns
  chassis.arc(31, 33); // swing -> intake ring 4
  //wait(500, msec);

  // ladder touch
  //chassis.drive_distance(-23, 88); // drive -> ladder
  chassis.turn(-115); // turn -> ladder
  //thread liftx = thread(lift_score);
  chassis.move(40, 10); // drive -> ladder
  wait(200, msec);
  l.stop();
  r.stop();
}

void blue_right() {
// preload -> alliance stake
  // lift_grab();
  // moveIntake(12);
  // wait(500, msec);
  // chassis.turn_to_angle(50);
  // moveIntake(0);
  // chassis.drive_distance(4.5);
  // moveLift(620, 100);
  // wait(500, msec);

  // // clamp mogo
  // thread liftReset = thread(lift_reset);
  // chassis.drive_max_voltage = 6;
  // chassis.turn_to_angle(19);
  // //thread wc = thread(wait_and_clamp);
  // chassis.drive_distance(-32);
  // mogo.set(true);
  // wait(500, msec);
  // moveIntake(12);

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

  thread t = thread(filterRed);

  // mogo 1 clamp
  chassis.move(-19); // drive -> mogo
  chassis.turn(-27);
  chassis.move(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  moveIntake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // rings 1 & 2
  chassis.turn(-149);
  chassis.move(23);
  wait(500, msec);

  // ring 3
  chassis.move(-5);
  chassis.turn(-130);
  chassis.move(8.5);
  wait(500, msec);

  // ring 4
  chassis.move(-20);
  wait(500, msec);
  arcs(); // enable arc turns
  chassis.arc(22.5, -29);
  wait(500, msec);

  // LADDER TOUCH
  chassis.turn(107);
  chassis.move(42);
}

void red_right() {
  thread t = thread(filterBlue);

  // mogo 1 clamp
  chassis.move(-19); // drive -> mogo
  chassis.turn(-27);
  chassis.move(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  moveIntake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // ring 2
  chassis.turn(-113.5);
  chassis.move(20);
  wait(1000, msec);

  // ladder touch
  chassis.move(-18);
  chassis.turn(-51.5);
  chassis.move(-30);
}

void blue_left() {
  thread t = thread(filterRed);

  // mogo 1 clamp
  chassis.move(-19); // drive -> mogo
  chassis.drive_max_voltage = 6;
  chassis.turn(27);
  chassis.move(-6);
  wait(10, msec);
  mogo.set(true); // clamp mogo
  moveIntake(12);
  wait(500, msec);
  chassis.drive_max_voltage = 10;

  // ring 2
  chassis.turn(110);
  chassis.move(20);
  wait(1000, msec);

  // ladder touch
  chassis.move(-18);
  chassis.turn(51.5);
  wait(1000, msec);
  chassis.move(-30);
  wait(200, msec);
  l.stop();
  r.stop();
}

#pragma region

void stopIntake() {
  moveIntake(0);
}

void moveIntake() {
  moveIntake(12);
}

void autoSkills() {
  // preload -> ally stake
  moveLift(LIFT_GRAB_POS, 100);
  moveIntake(12);
  wait(500, msec);
  moveIntake(0);
  moveLift(LIFT_SCORE_POS, 100);
  wait(500, msec);

  // mogo 1
  chassis.move(-9.75);
  thread resetLift = thread(lift_reset);
  chassis.turn(-90);
  chassis.move(-18, 3);
  mogo.set(true);
  //wait(500, msec);
  thread runIntake = thread(moveIntake);

  // ring 2
  chassis.turn(163);//167
  chassis.move(21);
  //wait(500, msec);

  // ring 3
  chassis.turn(129);//125
  chassis.move(43, 6);
  //wait(500, msec);//1000

  // rings 4
  chassis.move(-12.5);
  chassis.turn(0);
  chassis.move(10);
  //wait(1000, msec);//1k, 1500

  // ring 5
  chassis.move(25);//20
  //wait(1500, msec); //1500

  // ring 6
  chassis.move(18);
  //wait(1500, msec);//1500

  // ring 7
  chassis.turn(130);//120, 118
  chassis.move(9.5);
  //wait(1000, msec);

  // unclamp mogo 1 -> corner
  chassis.turn(-142);//212,207
  chassis.move(-9.5);//-8
  //wait(500, msec); <- see if needed later after standoffs added
  moveIntake(-12);
  mogo.set(false);
  //chassis.turn(230);

  // mogo 2
  chassis.move(11);//7.5
  chassis.turn(90);
  chassis.move(-50);
  chassis.move(-20, 4);
  mogo.set(true);
  wait(200, msec);

  // ring 8
  thread moi = thread(moveIntake);
  chassis.turn(-167);//165, 108
  chassis.move(21);//20
  //wait(1000, msec);

  // ring 9
  chassis.turn(-129);//230, 140
  chassis.move(43, 6);
  //wait(1000, msec);

  // ring 10
  chassis.move(-12.5);
  chassis.turn(0);
  chassis.move(10);
  //wait(1500, msec);//1k, 1500

  // ring 11
  chassis.move(25);//20
  //wait(1500, msec); //1500

  // ring 12
  chassis.move(18);
  //wait(1500, msec);//1500

  // ring 13
  chassis.turn(-130);//120, 118
  chassis.move(9.5);
  //wait(1000, msec);

  // mogo 2 unclamo
  chassis.turn(142);//212,207
  chassis.move(-9.5);//-8
  //wait(500, msec); <- see if needed later after standoffs added
  moveIntake(-12);
  mogo.set(false);
  //chassis.turn(230);

  // hang tier 1
  // chassis.move(60);
  // chassis.turn(-38);
  // chassis.move(-12, 3, 10000);

  // NOTE
  // increase distance for rings 4, 5 , and 6

  // ring 5
  //chassis.move(12);
  //
  
  // // mogo 1
  // chassis.move(14);
  // thread stop_intake = thread(stopIntake);
  // chassis.turn(90, m);
  // chassis.move(-18, 3);
  // mogo.set(true);
  // wait(500, msec);
  // thread spin_intake = thread(moveIntake);

  // // ring 2
  // chassis.turn(-17);
  // chassis.move(21);
  // wait(500, msec);

  // // ring 3
  // chassis.turn(-57);
  // chassis.move(38);

}

void autoskills() {
  //chassis.Gyro.setrotationSensor(90, deg);

  chassis.move(-30);
  chassis.move(-20, 4);
  mogo.set(true);
  wait(200, msec);
  thread moi = thread(moveIntake);

  chassis.turn(198);//108
  chassis.move(20);
  wait(1000, msec);

  chassis.turn(230);//140
  chassis.move(45);
  wait(1000, msec);

  chassis.move(-7.5);
  chassis.turn(0);
  chassis.move(10, 7);
  wait(1500, msec);

  chassis.move(20, 7);
  wait(1500, msec); 

  // ring 6
  chassis.move(20, 7);
  wait(1500, msec);

  chassis.turn(-118);
  chassis.move(9.5);
  wait(1000, msec);

  chassis.turn(-209);
  chassis.move(-15);
  wait(1000, msec);
  moveIntake(-8);
  mogo.set(false);
}