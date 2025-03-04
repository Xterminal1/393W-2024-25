#include "states-autons.h"


void turnNGS(float angle) {
    chassis.set_turn_constants(12, 0.4, 0.03, 3.2, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);
    chassis.turn(angle);
  }
  
void turnNGL(float angle) {
    chassis.set_turn_constants(12, 0.4, 0.03, 3.8, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);
    chassis.turn(angle);
  }
  
  void turnGS(float angle) {
    chassis.set_turn_constants(12, 0.4, 0.03, 3.5, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);
    chassis.turn(angle);
  }
  
  void turnGL(float angle) {
    chassis.set_turn_constants(12, 0.4, 0.03, 4.1, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);
    chassis.turn(angle);
  }

void move25_5() { chassis.move(25, 5.5); }
void move5_5() { chassis.move(5.5); }
void turn58() { turnNGS(58); }

void redLeft() {
    //thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);

    // mogo 1 clamp
    chassis.move(-18.2);
    turnNGS(27); //chassis.turn(27);
    chassis.move(-7);
    mogo.set(true);
    moveIntake(12);
    wait(300, msec);

    // rings 1 & 2
    //chassis.turn_kd = 3.45;
    turnGL(149); //chassis.turn(149);
    chassis.move(23);

    // ring 3
    chassis.move(-5);
    turnGS(130); //chassis.turn(130);
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

void redLeft2() {
    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);

    // preload -> alliance stake
    thread liftToLoad = thread(lift_grab);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(500, msec);

    // clamp mogo
    chassis.move(-23);
    chassis.move(-10, 3.5);
    mogo.set(true);
    wait(200, msec);
    moveIntake(12);

    // ring 2
    chassis.turn_kd = 4.5;
    chassis.turn(167);
    chassis.move(21);

    // ring 3
    chassis.turn(129);
    chassis.move(9.5);


    // turn 162
    // drive 21

    // drive 7
    // turn 58
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


void intakeMax() {
    moveIntake(12);
}

void SKILLS() {

    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);

    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 100, 3000);

    // preload -> ally stake
    moveLift(LIFT_GRAB_POS, 100);
    moveIntake(12);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(500, msec);

    // mogo 1
    chassis.move(-5.5);//-8.75
    thread lr = thread(liftNonReset);
    turnNGS(-90);
    chassis.move(-18, 3);
    mogo.set(true);
    chassis.drive_settle_error = 0.5;
    wait(200, msec);
    moveIntake(12);

    // ring 2
    chassis.turn_max_voltage = 6; turnGL(163); //chassis.turn(163, 6);
    chassis.move(21, 12);
    wait(500, msec);

    // ring 3
    chassis.turn_max_voltage = 12; turnGS(147); //chassis.turn(147);
    chassis.move(34.5, 12);
    turnGS(90); //chassis.turn(90);
    thread xk = thread(lift_grab);
    chassis.move(15.5, 12);
    wait(1000, msec);
    moveIntake(0);
    moveLift(520, 100);

    // ring 4/5/6
    chassis.move(-10.3, 12);
    thread lr2 = thread(liftNonReset);
    turnGS(0); //chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(700, msec);

    // ring 6
    turnGL(125); //chassis.turn(125);
    chassis.move(13);

    // unclamp mogo 1 -> corner
    turnGL(-160); //chassis.turn(-160, 12);
    chassis.move(-9);
    moveIntake(-12);
    mogo.set(false);

    // mogo 2
    chassis.move(9);//7.5
    turnNGL(90); //chassis.turn(90);
    chassis.move(-60, 12);
    chassis.move(-16.5, 3);
    mogo.set(true);
    wait(200, msec);

    // ring 1
    moveIntake(12);
    turnGL(-170); //chassis.turn(-170);
    chassis.move(16, 12);
    
    // ring 2 -> wall stake
    turnGS(-147); //chassis.turn(-147);
    chassis.move(39, 12);
    turnGS(-90); //chassis.turn(-90);
    thread xk2 = thread(liftGrab2);
    chassis.move(14.5, 12);
    wait(1000, msec);
    moveIntake(0);
    moveLift(520, 100);

    // ring 3/4/5
    chassis.move(-9.75, 12);
    thread lr3 = thread(liftNonReset);
    turnGS(0); //chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(700, msec);

    // 41 seconds

    // ring 6
    turnGL(-130); //chassis.turn(-130, 12);
    chassis.move(15);

    // unclamp mogo 2 -> corner
    turnGL(160); //chassis.turn(160, 12);
    chassis.move(-10);
    moveIntake(-12);
    mogo.set(false);

    // ally stake ring
    chassis.move(43, 12);
    moveIntake(12);
    thread xk3 = thread(liftGrab2);
    turnNGS(180);
    chassis.move(43, 12);
    wait(500, msec);
    
    // mogo 3 clamp
    turnNGL(-65);
    chassis.move(-35, 12);
    chassis.move(-12, 3.5);
    mogo.set(true);

    // ring -> ally stake
    chassis.move(-9);
    turnGL(180);
    chassis.move(2.5);
    moveIntake(0);
    lift_score();
    wait(500, msec);

    // ring 1 -> mogo 3
    chassis.move(-7);
    turnGS(-90);
    thread intakeStart = thread(intakeMax);
    chassis.move(43);



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