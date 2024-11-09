#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  // constant: 47.0119216518, starti: 40, max_integral: 14.5
  // Converting encoder units to inches: https://www.desmos.com/calculator/5xmwm3qp4b
  // Calculating Euclidean distances: https://www.desmos.com/calculator/mh9umhcuo3
  chassis.set_drive_constants(10, 0.8, 0.01, 3, 0); // 12, 0.8, 0, 3, 0 0.85
  chassis.set_heading_constants(6, 0.1, 0, 0, 0); // 6, 0.1, 0, 0, 0
  chassis.set_turn_constants(10, 0.8, 0, 7, 15); // 12, 12, 0.5, 0.03, 3, 15
  chassis.set_swing_constants(12, 0.8, 0, 7, 15); // 12, 0.2, 0, 0.1, 15

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(1.5, 300, 4000);
  chassis.set_turn_exit_conditions(1, 300, 1000); // 1, 300, 1000
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void auto_blue_right() {
  int intake_time = 350; // msec

  // mogo 1
  chassis.drive_distance(-22); // drive -> mogo
  wait(10, msec);
  mogo.set(true); // clamp mogo

  // preload / ring 1
  chassis.turn_max_voltage = 6;
  move_intake(12); // intake preload
  wait(intake_time, msec);

  // ring 2
  chassis.turn_to_angle(-112); //-112
  chassis.drive_distance(29); //30
  wait(intake_time, msec);

  // ring 3
  chassis.turn_to_angle(180); //-175
  chassis.drive_distance(12); //18
  wait(intake_time, msec);

  // ring 4
  chassis.drive_distance(-10);
  chassis.turn_to_angle(160);//165
  chassis.drive_distance(13);//12
  wait(intake_time, msec);

  // ladder touch
  chassis.drive_distance(-20); // drive bwd
  chassis.turn_to_angle(115); // turn -> ladder
  chassis.drive_distance(35); // drive -> ladder
  wait(50, msec);
  l.stop();
  r.stop();

}

void auto_red_left() {
  int intake_time = 350; // msec

  // mogo 1 clamp
  chassis.drive_distance(-22); // drive -> mogo
  wait(10, msec);
  mogo.set(true); // clamp mogo

  // preload / ring 1
  chassis.turn_max_voltage = 6;
  move_intake(12); // intake preload
  wait(200, msec);

  // ring 2
  chassis.turn_to_angle(112); // turn -> ring 2
  chassis.drive_distance(29); // drive -> ring 2

  // ring 3
  chassis.turn_to_angle(180);
  chassis.drive_distance(12);
  wait(2000, msec);

  // ring 4
  chassis.drive_distance(-10);
  chassis.turn_to_angle(-160);
  chassis.drive_distance(13);

  // ladder touch
  chassis.drive_distance(-20); // drive bwd
  chassis.turn_to_angle(-115); // turn -> ladder
  chassis.drive_distance(35); // drive -> ladder
  wait(50, msec);
  l.stop();
  r.stop();
}

void auto_red_right() {
  int intake_time = 350; // msec

  // mogo 1 clamp
  chassis.drive_distance(-22); // drive -> mogo
  wait(10, msec);
  mogo.set(true); // clamp mogo

  // preload / ring 1
  move_intake(12); // intake preload
  wait(450, msec);

  // ring 2 (partial intake)
  chassis.turn_to_angle(-112); // turn -> ring 2
  chassis.drive_distance(29); // drive -> ring 2
  move_intake(0);

  // mogo 1 unclamp
  chassis.turn_max_voltage = 6;
  chassis.turn_to_angle(160);
  chassis.drive_distance(-22);
  mogo.set(false);

  // mogo 2 clamp
  chassis.drive_distance(12);
  chassis.turn_to_angle(-3.5);
  chassis.drive_distance(-23);
  chassis.turn_max_voltage = 10;
  mogo.set(true);
  wait(50, msec);
  move_intake(12);

  // ladder touch
  chassis.turn_to_angle(45);
  chassis.drive_distance(29);
  chassis.turn_to_angle(135);
  chassis.drive_distance(27);
}

void auto_blue_left() {
  int intake_time = 350; // msec

  // mogo 1 clamp
  chassis.drive_distance(-22); // drive -> mogo
  wait(10, msec);
  mogo.set(true); // clamp mogo

  // preload / ring 1
  chassis.turn_max_voltage = 6;
  move_intake(12); // intake preload
  wait(200, msec);

  // ring 2 (partial intake)
  chassis.turn_to_angle(112); // turn -> ring 2
  chassis.drive_distance(29); // drive -> ring 2
  move_intake(0);

  // mogo 1 unclamp
  chassis.turn_max_voltage = 6;
  chassis.turn_to_angle(-160);
  chassis.drive_distance(-22);
  mogo.set(false);

  // mogo 2 clamp
  chassis.drive_distance(12);
  chassis.turn_to_angle(14);
  chassis.drive_distance(-23);
  chassis.turn_max_voltage = 6;
  mogo.set(true);
  wait(300, msec);
  move_intake(12);

  // ladder touch
  chassis.turn_to_angle(-45);
  chassis.drive_distance(29);
  chassis.turn_to_angle(-135);
  chassis.drive_distance(27);
}

void auto_skills() {
  int intake_time = 350;
  chassis.drive_max_voltage = 12;
  chassis.turn_max_voltage = 9;
  chassis.drive_kp = 0.8;
  chassis.drive_ki = 0.03;
  chassis.drive_kd = 5;
  chassis.turn_kp = 0.8;
  chassis.turn_ki = 0;
  chassis.turn_kd = 7;

  // alliance stake
  move_intake(12);
  wait(500, msec);

  // mogo 1 clamp
  chassis.drive_distance(13);
  move_intake(0);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-12);
  mogo.set(true);
  wait(500, msec);

  // ring 1
  move_intake(12);
  chassis.drive_max_voltage = 6;
  chassis.turn_to_angle(-25);
  chassis.drive_distance(27.5); 

  // ring 2
  chassis.turn_to_angle(-90);
  chassis.drive_distance(28);

  // ring 3
  chassis.turn_to_angle(-18);
  chassis.drive_distance(31);

  // ring 4
  chassis.drive_distance(-37);
  chassis.turn_to_angle(165);
  chassis.drive_distance(20);

  // ring 5
  chassis.turn_to_angle(-173);
  chassis.drive_distance(14.5);
  wait(1000, msec);

  // ring 6
  chassis.turn_to_angle(-45);
  chassis.drive_distance(12);
  wait(1000, msec);

  // mogo 1 unclamp -> corner
  chassis.turn_to_angle(25);
  wait(2000, msec);
  chassis.drive_distance(-8);
  mogo.set(false);
  move_intake(-12);

  // mogo 2 clamp
  chassis.drive_distance(10);
  move_intake(0);
  chassis.drive_max_voltage = 4;
  chassis.turn_to_angle(-90);
  chassis.drive_distance(-71);
  mogo.set(true);
  move_intake(12);

  // ring 1
  chassis.turn_to_angle(90);
  chassis.drive_distance(29);


}

void rl10() {
  // start (x=-56.325, y=14.249, h=90h/0r)
  // intake front, mogo back

  int intake_time = 250;

  // preload to ally stake
  chassis.turn_to_angle(-50); // turn -> ally stake
  chassis.drive_distance(-2.387); // drive -> ally stake if lift
  // chassis.drive_distance(-8.538); if no lift
  // [move lift to ally stake position or intake]

  // mogo 1
  chassis.drive_distance(27.65); // drive -> m1 gl
  chassis.turn_to_angle(210); // turn -> m1
  chassis.drive_distance(-7.906); // drive -> m1
  mogo.set(true);

  // ring 2
  move_intake(true);
  chassis.turn_to_angle(-68); // turn -> r2
  // decrease if robot pushes ring away
  //                       |
  //                       |
  //                       V
  chassis.drive_distance(14.6); // drive -> r2
  wait(intake_time, msec);

  // ring 3
  chassis.turn_to_angle(-3);
  chassis.drive_distance(13.616);
  wait(intake_time, msec);
  // ring 4
}

#pragma region
// test autons
/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

/**
 * The expected behavior is to return to the start position.
 */

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

/**
 * The expected behavior is to return to the start angle, after making a complete turn.
 */

void turn_test(){
  chassis.turn_to_angle(5);
  chassis.turn_to_angle(30);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(225);
  chassis.turn_to_angle(0);
}

/**
 * Should swing in a fun S shape.
 */

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/**
 * Doesn't drive the robot, but just prints coordinates to the Brain screen 
 * so you can check if they are accurate to life. Push the robot around and
 * see if the coordinates increase like you'd expect.
 */

void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5,20, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(5,40, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(5,60, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5,80, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(5,100, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

/**
 * Should end in the same place it began, but the second movement
 * will be curved while the first is straight.
 */

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

/**
 * Drives in a square while making a full turn in the process. Should
 * end where it started.
 */

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_pose(0, 18, 90);
  chassis.holonomic_drive_to_pose(18, 0, 180);
  chassis.holonomic_drive_to_pose(0, 18, 270);
  chassis.holonomic_drive_to_pose(0, 0, 0);
}
#pragma endregion