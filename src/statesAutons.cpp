#include "statesAutons.h"

void move25_5() { chassis.move(25, 5.5); }

void redLeft() {
    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);
    
    chassis.drive_settle_error = 0.5;
    chassis.drive_settle_time = 100;
    chassis.turn_settle_time = 150;
    intake.setMaxTorque(100, percent);

    // mogo 1 clamp
    chassis.move(-18.2);
    chassis.turn(27);
    chassis.move(-6);
    mogo.set(true);
    moveIntake(12);
    wait(300, msec);

    // rings 1 & 2
    chassis.turn_kd = 3.6;
    chassis.turn(149);
    chassis.move(23);

    // ring 3
    chassis.move(-5);
    chassis.turn(130);
    chassis.move(8.5);

    // ring 4
    chassis.move(-20);
    arcs();
    chassis.arc(18, 50);

    // ring 5 -> ally stake
    // chassis.turn(-57);
    // chassis.move(38);
    // COLOR_SORT_FILTER_BLUE.interrupt();
    // thread COLOR_SORT_FILTER_BLUE_SLOW = thread(filterBlueSlow);
    // thread MOVE_25_IN = thread(move25_5);
    // wait(1700, msec);
    // lift_grab();
}


void blueRight() {

    thread COLOR_SORT_FILTER_RED = thread(filterRed);
  
    chassis.turn_kd = 3.8;
    chassis.drive_settle_error = 0.5;
    chassis.drive_settle_time = 100;
    chassis.turn_settle_time = 150;
    intake.setMaxTorque(100, percent);
  
    // mogo 1 clamp
    chassis.move(-19);
    chassis.turn(-27);
    chassis.move(-6);
    mogo.set(true);
    moveIntake(12);
    wait(300, msec);
  
    // rings 1 & 2
    chassis.turn(-149);
    chassis.move(23);
  
    // ring 3
    chassis.move(-5);
    chassis.turn(-130);
    chassis.move(8.5);
  
    // ring 4
    chassis.move(-20);
    arcs();
    chassis.arc(18, -50);
  
    // ring 5 -> ally stake
    chassis.turn(57);
    chassis.move(38);
    thread MOVE_25_IN = thread(move25_5);
    detectRedRing();
    lift_grab();
}

void liftGrab2() {
    moveLift(140, 100);
}

void SKILLS() {

    chassis.drive_settle_error = 1.5;
    chassis.drive_settle_time = 300;
    chassis.turn_settle_time = 150;
    intake.setMaxTorque(100, percent);

    // preload -> ally stake
    moveLift(LIFT_GRAB_POS, 100);
    moveIntake(12);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(500, msec);

    // mogo 1
    chassis.move(-10.2);
    thread resetLift1 = thread(lift_reset);
    chassis.turn(-90);
    chassis.move(-18, 3);
    mogo.set(true);
    wait(200, msec);
    moveIntake(12);

    // ring 2
    chassis.turn_kd = 3.6;
    chassis.turn(163);
    chassis.move(21, 6);
    wait(500, msec);

    // ring 3
    chassis.turn(147);
    chassis.move(32.5, 6);
    chassis.turn(90);
    thread xk = thread(lift_grab);
    chassis.move(17);
    wait(1000, msec);
    moveIntake(0);
    moveLift(450, 100);

    //chassis.set_heading_constants(9, 0.13, 0.003, 1.5, 15);
    // chassis.drive_settle_error = 1.5;
    // chassis.drive_settle_time = 300;

    // chassis.arc(37, 90);
    // moveLift(140, 100);
    // chassis.set_heading_constants(12, 0, 0, 0, 0);
    // chassis.drive_settle_error = 0.5;
    // chassis.drive_settle_time = 100;
    // chassis.move(8);
    // wait(1000, msec);
    // moveIntake(0);
    // moveLift(LIFT_WALL_STAKE_POS, 100);
    // wait(500, msec);

    // ring 4/5/6
    chassis.heading_kp = .05;
    chassis.move(-12, 6);
    thread resetLift2 = thread(lift_reset);
    chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(500, msec);

    // ring 6
    chassis.turn(125, 4);
    chassis.move(15);
    wait(100, msec);

    // unclamp mogo 1 -> corner
    chassis.turn(-160, 9);
    chassis.move(-12);
    moveIntake(-12);
    mogo.set(false);

    // mogo 2
    chassis.move(8);//7.5
    
    chassis.turn(90);
    chassis.move(-60, 8);
    chassis.move(-16.5, 4);
    mogo.set(true);
    wait(200, msec);

    // ring 1
    moveIntake(12);
    chassis.turn(-170);
    chassis.move(16, 6);
    
    // ring 2
    chassis.turn(-147);
    chassis.move(35.7, 6);
    chassis.turn(-90);
    thread xk2 = thread(liftGrab2);
    chassis.move(17);
    wait(1000, msec);
    moveIntake(0);
    moveLift(450, 100);

    // ring 3/4/5
    chassis.heading_kp = .05;
    chassis.move(-10.5, 6);
    thread resetLift26 = thread(lift_reset);
    chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(500, msec);

    // ring 6
    chassis.turn(-130, 12);
    chassis.move(15);
    wait(100, msec);

    // unclamp mogo 2 -> corner
    chassis.turn(160, 12);
    chassis.move(-12);
    moveIntake(-12);
    mogo.set(false);

    // -6, 163
    // 32, 289

    // ring 3
    // chassis.turn(129);
    // chassis.move(43);

    // rings 4
    // chassis.move(-13.5);
    // chassis.turn(0);
    // chassis.move(52, 5);
}