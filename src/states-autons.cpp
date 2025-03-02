#include "states-autons.h"

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
    chassis.turn_kd = 3.45;
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

void liftNonReset() {
    moveLift(350, 100);
}

void SKILLS() {

    chassis.drive_settle_error = 0.5;
    chassis.drive_settle_time = 100;
    chassis.turn_settle_error = 1;
    chassis.turn_settle_time = 300;
    //intake.setMaxTorque(100, percent);

    // preload -> ally stake
    moveLift(LIFT_GRAB_POS, 60);
    moveIntake(12);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 60);
    wait(500, msec);

    // mogo 1
    chassis.move(-8.75);
    thread lr = thread(liftNonReset);
    chassis.turn(-90);
    chassis.move(-18, 3);
    mogo.set(true);
    wait(200, msec);
    moveIntake(12);

    // ring 2
    chassis.turn_kd = 3.6;
    chassis.turn(163, 6);
    chassis.move(21, 12);
    wait(500, msec);

    // ring 3
    chassis.turn(147);
    chassis.move(33.5, 12);
    chassis.turn(90);
    thread xk = thread(lift_grab);
    chassis.move(16.3, 12);
    wait(1000, msec);
    moveIntake(0);
    moveLift(550, 60);

    // ring 4/5/6
    chassis.move(-10.3, 12);
    thread lr2 = thread(liftNonReset);
    chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(700, msec);

    // ring 6
    chassis.turn(125, 12);
    chassis.move(15);
    wait(100, msec);

    // unclamp mogo 1 -> corner
    chassis.turn(-160, 12);
    chassis.move(-12);
    moveIntake(-12);
    mogo.set(false);

    // mogo 2
    chassis.move(7);//7.5
    chassis.turn(90);
    chassis.move(-60, 12);
    chassis.move(-16.5, 3);
    mogo.set(true);
    wait(200, msec);

    // ring 1
    moveIntake(12);
    chassis.turn(-170);
    chassis.move(16, 12);
    
    // ring 2
    chassis.turn(-147);
    chassis.move(36.5, 12);
    chassis.turn(-90);
    thread xk2 = thread(liftGrab2);
    chassis.move(16, 12);
    wait(1000, msec);
    moveIntake(0);
    moveLift(550, 60);

    // ring 3/4/5
    chassis.move(-10.5, 12);
    thread lr3 = thread(liftNonReset);
    chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(700, msec);

    // ring 6
    chassis.turn(-130, 12);
    chassis.move(15);
    wait(100, msec);

    // unclamp mogo 2 -> corner
    chassis.turn(160, 12);
    chassis.move(-10);
    moveIntake(-12);
    mogo.set(false);

    // ally stake ring
    chassis.move(43, 12);
    moveIntake(12);
    thread xk3 = thread(liftGrab2);
    chassis.turn(180);
    chassis.move(43, 12);
    wait(500, msec);
    chassis.turn(-65);
    chassis.move(-35, 12);
    chassis.move(-12, 3.5);
    mogo.set(true);
    chassis.move(-6);
    chassis.turn(180);
    chassis.move(2.5);
    wait(1000, msec);
    moveIntake(0);
    lift_score();


    // move 43
    // turn 180
    // move 43
    // turn 115 relative to 180
    // move -47 (-53 after clamping (total))
    // move 2.5 in
    // lb -> ally stake


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