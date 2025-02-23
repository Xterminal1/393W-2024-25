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
    move_intake(12);
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

/*



*/

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
    move_intake(12);
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