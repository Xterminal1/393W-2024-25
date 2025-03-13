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
void move_neg44_6 () { chassis.move(-44, 6); }
void move5_5() { chassis.move(5.5); }
void turn58() { turnNGS(58); }

void liftVertical() { moveLift(350, 100); }

void RED_LEFT() {
    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 50, 3000);

    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    // preload -> alliance stake
    thread liftToLoad = thread(lift_grab);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(150, msec);

    // clamp mogo
    thread mng446 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    
    // ring 2
    chassis.turn_kd = 4.1;
    chassis.turn(157);//167
    chassis.move(9.5);//11

    // ring 3
    chassis.turn_kd = 3.7;
    chassis.turn(129);
    chassis.move(9.1);

    // ring 4
    chassis.move(-17);
    wait(200, msec);
    chassis.set_heading_constants(12, .6, .001, 8, 0);
    chassis.arc(18, 50);
    wait(800, msec);

    // ring 5
    chassis.turn(-27.5);
    intakePiston.set(true);
    chassis.move(35);
    chassis.move(9.5);
    intakePiston.set(false);
    wait(1000, msec);

    // ladder touch
    chassis.move(-10, 3.5);
    thread liftreset = thread(lift_reset);
    chassis.turn(60.5, 6);
    wait(500, msec);
    chassis.move(-17);
}

void BLUE_RIGHT() {
    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 50, 3000);

    thread COLOR_SORT_FILTER_RED = thread(filterRed);

    // preload -> alliance stake
    thread liftToLoad = thread(lift_grab);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(150, msec);

    // clamp mogo
    thread mng446 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    
    // ring 2
    chassis.turn_kd = 4.1;
    chassis.turn(-157);//167
    chassis.move(9.5);//11

    // ring 3
    chassis.turn_kd = 3.7;
    chassis.turn(-129);
    chassis.move(9.1);

    // ring 4
    chassis.move(-17);
    wait(200, msec);
    chassis.set_heading_constants(12, .6, .001, 8, 0);
    chassis.arc(18, -50);
    wait(800, msec);

    // ring 5
    chassis.turn(27.5);
    intakePiston.set(true);
    chassis.move(35);
    chassis.move(9.5);
    intakePiston.set(false);
    wait(1000, msec);

    // ladder touch
    chassis.move(-10, 3.5);
    thread liftreset = thread(lift_reset);
    chassis.turn(-60.5, 6);
    wait(500, msec);
    chassis.move(-17);
}

void threaddistance () { chassis.move(-39, 6); }

void BLUE_LEFT() {
    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 50, 3000);

    thread COLOR_SORT_FILTER_RED = thread(filterRed);

    // clamp mogo
    thread mng44612 = thread(threaddistance);
    wait(1300, msec);
    mogo.set(true);
    wait(500, msec);
    moveIntake(12); // score preload

    // ring 2
    chassis.turn_kd = 3.6;
    chassis.turn(45);
    chassis.move(25);

    // ring 3
    chassis.turn(-89);
    intakePiston.set(true);
    chassis.move(35.5);
    chassis.move(9, 3.5);
    intakePiston.set(false);
    wait(2000, msec);

    chassis.move(-10, 3.5);
    thread liftreset = thread(lift_reset);
}

void move_neg33_6 () { chassis.move(-27.5, 6); }

void RED_SOLO_AWP() {
    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 50, 3000);

    // preload -> alliance stake
    thread liftToLoad = thread(lift_grab);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(150, msec);

    // clamp mogo
    thread mng446_2 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    thread lift_vertical = thread(liftVertical);

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
    chassis.set_heading_constants(9, 0.6, .001, 6, 0);
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
    thread lift_reset2 = thread(lift_reset);
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
    chassis.set_drive_constants(12, 1.2, 0, 10, 0);
    chassis.set_drive_exit_conditions(.75, 100, 5000);
    chassis.set_turn_constants(12, 0.4, 0.03, 3, 15);
    chassis.set_turn_exit_conditions(.5, 50, 3000);

    // preload -> alliance stake
    thread liftToLoad = thread(lift_grab);
    moveIntake(12);
    thread move_5_5 = thread(move5_5);
    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(150, msec);

    // clamp mogo
    thread mng446_2 = thread(move_neg44_6);
    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);
    thread lift_vertical = thread(liftVertical);

    // ring 2
    chassis.turn_kd = 4.4;
    chassis.turn(-157);//167
    chassis.move(9.5);//11

    // ring 3
    chassis.turn_kd = 3.7;
    chassis.turn(-129);
    chassis.move(8.2);

    // unclamp mogo 1
    chassis.set_heading_constants(9, 0.6, .001, 6, 0);
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
    thread lift_reset2 = thread(lift_reset);
    chassis.move(-27);
    wait(200, msec);
    l.stop();
    r.stop();
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

float getPos() {     
    return (chassis.get_left_position_in() + chassis.get_right_position_in()) / 2;
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
    chassis.move(-7.1);//-8.75
    
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
    chassis.move(34, 12);//34.75
    turnGS(90); //chassis.turn(90);
    thread xk = thread(lift_grab);
    chassis.move(15.8, 12);
    wait(1000, msec);
    moveIntake(0);
    moveLift(520, 100);

    // ring 4/5/6
    chassis.move(-11, 12);//=10.3
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
    turnGL(-155); //chassis.turn(-160, 12);
    wait(500, msec);
    mogo.set(false);
    chassis.move(-10);//-6.5
    moveIntake(-12);

    // mogo 2
    chassis.move(5.5);//7.5
    turnNGL(90); //chassis.turn(90);
    ///chassis.set_heading_constants(0, 0, 0, 0, 0);
    chassis.move(-60, 12);
    chassis.move(-16.5, 3);
    mogo.set(true);
    wait(200, msec);

    // ring 1
    moveIntake(12);
    turnGL(-170); //chassis.turn(-170);
    chassis.set_heading_constants(6, .4, 0, 1, 0);
    chassis.move(16, 12);
    
    // ring 2 -> wall stake
    turnGS(-147); //chassis.turn(-147);
    chassis.move(37.1, 12);//38.1
    turnGS(-90); //chassis.turn(-90);
    thread xk2 = thread(liftGrab2);
    chassis.move(15.5, 12);
    wait(1000, msec);
    moveIntake(0);
    moveLift(520, 100);

    // ring 3/4/5
    chassis.move(-11.5, 12);//-10.75
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
    chassis.move(-15, 3.5);
    mogo.set(true);

    // ring -> ally stake
    chassis.move(-3.5);
    turnGL(180);
    chassis.move(2.5);
    moveIntake(0);
    lift_score();
    wait(500, msec);

    // ring 1 -> mogo 3
    chassis.move(-7);
    turnGS(-90);
    thread intakeStart = thread(intakeMax);
    chassis.move(44);
    wait(1000, msec);
    
    // unclamp mogo 3
    chassis.turn(45);
    wait(1000, msec);
    moveIntake(-12);
    mogo.set(false);
    chassis.drive_timeout = 600;
    chassis.move(-19.5);

    // push mogo 4 -> corner
    chassis.drive_timeout = 5000;
    chassis.move(25);
    chassis.turn(-70);
    chassis.move(-80);

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