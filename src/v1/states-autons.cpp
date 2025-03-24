#include "states-autons.h"

void turnNGS(float angle) {
    chassis.setAngularPID(12, 0.4, 0.03, 3.2, 15);
    chassis.setAngularExits(.5, 100, 3000);
    chassis.turn(angle);
  }
  
void turnNGL(float angle) {
    chassis.setAngularPID(12, 0.4, 0.03, 3.8, 15);
    chassis.setAngularExits(.5, 100, 3000);
    chassis.turn(angle);
  }
  
void turnGS(float angle) {
    chassis.setAngularPID(12, 0.4, 0.03, 3.5, 15);
    chassis.setAngularExits(.5, 100, 3000);
    chassis.turn(angle);
  }
  
void turnGL(float angle) {
    chassis.setAngularPID(12, 0.4, 0.03, 4.1, 15);
    chassis.setAngularExits(.5, 100, 3000);
    chassis.turn(angle);
  }

void move25_5() { chassis.move(25, 5.5); }
void move_neg44_6 () { chassis.move(-44, 6); }
void move5_5() { chassis.move(5.5); }
void turn58() { turnNGS(58); }

void RED_LEFT() {
    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 5000);
    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 50, 3000);

    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    // preload -> alliance stake
    thread liftToLoad = thread(liftLoad);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS);
    wait(150, msec);

    // clamp mogo
    thread mng446 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    
    // ring 2
    chassis.turn_kd = 4.1;
    chassis.turn(167);//167
    //thread lift_vertical = thread(liftVertical);
    thread liftreset = thread(liftReset);
    chassis.move(9.5);//11

    // ring 3
    chassis.turn_kd = 3.7;
    chassis.turn(129);
    chassis.move(9.1);

    // ring 4
    chassis.move(-17);
    wait(200, msec);
    chassis.setHeadingPID(12, .6, .001, 8, 0);
    chassis.arc(18, 50);
    //wait(800, msec);

    // ring 5
    chassis.turn(-27.5);
    intakePiston.set(true);
    chassis.move(35);
    chassis.move(9.5);
    intakePiston.set(false);
    wait(1000, msec);

    // ladder touch
    chassis.move(-25, 3.5);
    //thread liftreset = thread(lift_reset);
    chassis.turn(80, 12);
    wait(500, msec);
    chassis.move(-27);
    wait(200, msec);
    l.stop();
    r.stop();
    moveIntake(0);
}

void BLUE_RIGHT() {
    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 5000);
    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 50, 3000);

    thread COLOR_SORT_FILTER_RED = thread(filterRed);

    // preload -> alliance stake
    thread liftToLoad = thread(liftLoad);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS);
    wait(150, msec);

    // clamp mogo
    thread mng446 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    
    // ring 2
    chassis.turn_kd = 4.1;
    chassis.turn(-167);//167
    //thread lift_vertical = thread(liftVertical);
    thread liftreset = thread(liftReset);
    chassis.move(9.5);//11

    // ring 3
    chassis.turn_kd = 3.7;
    chassis.turn(-129);
    chassis.move(9.1);

    // ring 4
    chassis.move(-17);
    wait(200, msec);
    chassis.setHeadingPID(12, .6, .001, 8, 0);
    chassis.arc(18, -50);
    wait(800, msec);

    // ring 5
    chassis.turn(27.5);
    wait(1000, msec);
    moveIntake(0);



    //intakePiston.set(true);
    chassis.move(38);
    //chassis.move(9.5);
    // intakePiston.set(false);
    // wait(1000, msec);

    // ladder touch
    // chassis.move(-25, 3.5);
    // //thread liftreset = thread(lift_reset);
    // chassis.turn(-80, 12);
    // wait(500, msec);
    // chassis.move(-27);
    wait(200, msec);
    l.stop();
    r.stop();
    moveIntake(0);
}

void threaddistance () { chassis.move(-39, 6); }

void BLUE_LEFT() {
    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 5000);
    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 50, 3000);

    thread COLOR_SORT_FILTER_RED = thread(filterRed);

    // clamp mogo
    //thread lift_vertical = thread(liftVertical);
    thread mng44612 = thread(threaddistance);
    wait(1150, msec);
    mogo.set(true);
    wait(100, msec);
    
    // ring 2
    chassis.turn_kd = 3.3;
    chassis.turn(67);
    moveIntake(12); // score preload
    wait(500, msec);
    chassis.move(25);
    wait(500, msec);

    // ring 3
    chassis.turn(-64);
    intakePiston.set(true);
    chassis.move(35.5);
    chassis.move(9.5, 6);
    intakePiston.set(false);
    wait(1000, msec);
    chassis.move(-15, 3.5);
    wait(1000, msec);

    // back up
    chassis.move(-20);
    chassis.turn(-135);
    mogo.set(false);

    // go to goal 3
    chassis.move(12);
    chassis.turn(-45);  
    //chassis.move(-8);

    // ladder touch
    // chassis.move(-10);
    // //thread liftreset = thread(lift_reset);
    // chassis.turn(40);
    // chassis.move(-27);
    // wait(200, msec);
    // l.stop();
    // r.stop();
    // moveIntake(0);

    // sweep corner part
    // chassis.move(-10);
    // chassis.turn(45);
    // doink.set(true);vvvv
    // chassis.move(38.5);
    // chassis.turn(0);
    // wait(500, msec);
    // chassis.turn(45);
    // chassis.move(-47);
    // wait(200, msec);
    // l.stop();
    // r.stop();
    // moveIntake(0);
}

void RED_RIGHT() {
    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 5000);
    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 50, 3000);

    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    // clamp mogo
    //thread lift_vertical = thread(liftVertical);
    thread mng44612 = thread(threaddistance);
    wait(1150, msec);
    mogo.set(true);
    wait(100, msec);
    
    // ring 2
    chassis.turn_kd = 3.3;
    chassis.turn(-67);
    moveIntake(12); // score preload
    wait(500, msec);
    chassis.move(25);
    wait(500, msec);

    // ring 3
    // chassis.turn(64);
    // intakePiston.set(true);
    // chassis.move(35.5);
    // chassis.move(9.5, 3.8);
    // intakePiston.set(false);
    // wait(1000, msec);
    // chassis.move(-15, 3.5);
    // wait(1000, msec);

    // ladder touch
    // chassis.move(-10);
    // //thread liftreset = thread(lift_reset);
    // chassis.turn(-40);
    // chassis.move(-25.5);
    wait(1000, msec);
    l.stop();
    r.stop();
    moveIntake(0);

}

void move_neg33_6 () { chassis.move(-27.5, 6); }

void RED_SOLO_AWP() {
    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 5000);
    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 50, 3000);

    // preload -> alliance stake
    thread liftToLoad = thread(liftLoad);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS);
    wait(150, msec);

    // clamp mogo
    thread mng446_2 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    //thread lift_vertical = thread(liftVertical);
    thread liftreset = thread(liftReset);

    // ring 2
    chassis.turn_kd = 4.4;
    chassis.turn(157);//167
    chassis.move(9.5);//11

    // ring 3
    // chassis.move(-17);
    // chassis.set_heading_constants(12, .6, .001, 8, 0);
    // chassis.arc(16.5, 50);
    // wait(800, msec);
    // chassis.arc(47, 287);
    // mogo.set(true);
    chassis.turn_kd = 3.7;
    chassis.turn(129);
    chassis.move(8.2);

    // unclamp mogo 1
    chassis.setHeadingPID(9, 0.6, .001, 6, 0);
    chassis.arc(-46.5, 201);
    chassis.turn_kd = 4.4;
    chassis.turn(-67, 5);
    mogo.set(false);

    // mogo 2
    chassis.move(34);
    chassis.turn_kd = 3.7;
    chassis.turn(52);
    thread mng336 = thread(move_neg33_6);
    wait(800, msec);
    mogo.set(true);

    // ring 4
    chassis.turn_kd = 4.4;
    chassis.turn(-35);
    chassis.move(13.5);

    // ladder touch
    chassis.turn_kd = 3.76;
    chassis.turn(-46);
    //thread lift_reset2 = thread(lift_reset);
    chassis.move(-27);
    wait(200, msec);
    l.stop();
    r.stop();

    // NO ARC TURN, CROSSES LINE
    // chassis.turn(157);
    // chassis.move(-48);
    // chassis.turn_kd = 4.4;
    // chassis.turn(-67);
    // mogo.set(false);

    // chassis.move(15);
    // chassis.turn(82);
    // thread mng336_2 = thread(move_neg33_6);
    // wait(950, msec);
    // mogo.set(true);
    // moveIntake(12);

    // chassis.turn(-54);
    // chassis.move(11);
    // wait(500, msec);

}

void BLUE_SOLO_AWP() {
    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 5000);
    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 50, 3000);

    // preload -> alliance stake
    thread liftToLoad = thread(liftLoad);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS);
    wait(150, msec);

    // clamp mogo
    thread mng446_2 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    //thread lift_vertical = thread(liftVertical);
    thread liftreset = thread(liftReset);

    // ring 2
    chassis.turn_kd = 4.4;
    chassis.turn(-157);//167
    chassis.move(9.5);//11

    // ring 3
    chassis.turn_kd = 3.7;
    chassis.turn(-129);
    chassis.move(8.2);

    // unclamp mogo 1
    chassis.setHeadingPID(9, 0.6, .001, 6, 0);
    chassis.arc(-46.5, -201);
    chassis.turn_kd = 4.4;
    chassis.turn(67, 5);
    mogo.set(false);

    // mogo 2
    chassis.move(34);
    chassis.turn_kd = 3.7;
    chassis.turn(-52);
    thread mng336 = thread(move_neg33_6);
    wait(800, msec);
    mogo.set(true);

    // ring 4
    chassis.turn_kd = 4.4;
    chassis.turn(35);
    chassis.move(13.5);

    // ladder touch
    chassis.turn_kd = 3.3;
    chassis.turn(46);
    //thread lift_reset2 = thread(lift_reset);
    chassis.move(-27);
    wait(200, msec);
    l.stop();
    r.stop();
}

void RED_LEFT_ELIMS() {

}

void liftGrab2() {
    moveLift(140);
}

void liftNonReset() {
    moveLift(350);
}


void intakeMax() {
    moveIntake(12);
}

float getPos() {     
    return (chassis.get_left_position_in() + chassis.get_right_position_in()) / 2;
}

void SKILLS() {

    chassis.setLateralPID(12, 1.2, 0, 10, 0);
    chassis.setLateralExits(.75, 100, 1300);

    chassis.setAngularPID(12, 0.4, 0.03, 3, 15);
    chassis.setAngularExits(.5, 100, 3000);

    // preload -> ally stake
    //moveLift(LIFT_GRAB_POS, 100);
    liftGrab2();
    moveIntake(12);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS);
    wait(500, msec);

    // mogo 1
    chassis.move(-7.1);//-8.75
    thread liftreset = thread(liftReset); //thread lr = thread(liftNonReset);
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
    chassis.move(34.75, 12);//34
    turnGS(90); //chassis.turn(90);
    lift.setTimeout(1000, msec);
    thread xk = thread(liftGrab2);
    chassis.drive_timeout = 800;
    chassis.move(15.8, 12);
    chassis.drive_timeout = 2000;
    wait(1000, msec);
    l.setStopping(coast);
    r.setStopping(coast);
    moveIntake(0);
    lift.setTimeout(3000, msec);
    moveLift(520);


    // ring 4/5/6
    chassis.move(-10.3, 12);//=11
    l.setStopping(hold);
    r.setStopping(hold);
    thread lr2 = thread(liftNonReset);
    turnGS(0); //chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(700, msec);

    // ring 6
    turnGL(125); //chassis.turn(125);
    thread liftreset2 = thread(liftReset);
    chassis.move(13);

    // unclamp mogo 1 -> corner
    chassis.drive_timeout = 700;
    turnGL(-155); //chassis.turn(-160, 12);
    wait(500, msec);
    mogo.set(false);
    chassis.move(-6.5);//-10
    chassis.drive_timeout = 2000;
    moveIntake(-12);

    // mogo 2
    chassis.move(5.5);//7.5
    turnNGL(90); //chassis.turn(90);
    ///chassis.set_heading_constants(0, 0, 0, 0, 0);
    chassis.move(-60, 12);
    chassis.move(-16.5, 3);
    chassis.drive_timeout = 1000;
    mogo.set(true);
    wait(200, msec);

    // ring 1
    moveIntake(12);
    turnGL(-170); //chassis.turn(-170);
    chassis.setHeadingPID(6, .4, 0, 1, 0);
    chassis.move(16, 12);
    
    // ring 2 -> wall stake
    turnGS(-147); //chassis.turn(-147);
    chassis.move(37.5, 12);//38.1//37.1
    turnGS(-90); //chassis.turn(-90);
    //thread xk2 = thread(liftGrab2);
    chassis.drive_timeout = 500;
    //lift.setTimeout(1500, msec);
    chassis.move(16.2, 12);
    chassis.drive_timeout = 2000;
    //lift.setTimeout(1500, msec);
    wait(1000, msec);
    moveIntake(0);
    //moveLift(520, 100);

    // ring 3/4/5
    chassis.move(-11.5, 12);//-10.75
    thread lr3 = thread(liftNonReset);
    turnGS(0); //chassis.turn(0);
    moveIntake(12);
    chassis.move(43, 4);
    chassis.move(15, 3);
    wait(700, msec);

    // ring 6
    turnGL(-130); //chassis.turn(-130, 12);
    thread liftreset3 = thread(liftReset);
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
    chassis.move(-15, 3.5);
    mogo.set(true);

    // ring -> ally stake
    chassis.move(-3.5);//3.5
    turnGL(180);
    moveIntake(0);
    chassis.move(3.5);
    lift.setTimeout(1500, msec);
    liftScore();
    wait(200, msec);

    // ring 1 -> mogo 3
    chassis.move(-5.7);
    turnGS(-90);
    thread liftreset4 = thread(liftReset);
    thread intakeStart = thread(intakeMax);
    chassis.move(44);
    wait(1000, msec);
    
    // unclamp mogo 3
    chassis.turn(50);
    wait(500, msec);
    moveIntake(-12);
    chassis.drive_timeout = 600;
    chassis.move(-19.5);
    mogo.set(false);

    // push mogo 4 -> corner
    chassis.drive_timeout = 1000;
    chassis.move(25);
    chassis.turn(-70);
    chassis.drive_timeout = 5000;
    chassis.move(-100);

    // 135
    // 19.5 



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