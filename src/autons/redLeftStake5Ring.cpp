#include <vex.h>

void red_left_stake_5_ring() {

    std::cout << "AUTON BEGIN" << endl;

    intake.setMaxTorque(100, pct);
    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    // PRELOAD -> ALLIANCE STAKE
    thread liftGrabThread = thread(lift_grab);
    moveIntake(12);
    
    auto move_5_5in = []() { chassis.move(7.5); }; 
    thread move_5_5 = thread(move_5_5in);

    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(150, msec);

    // CLAMP MOGO
    auto move_neg_42_6v = []() { chassis.move(-41, 6); }; 
    thread move_neg_42_6 = thread(move_neg_42_6v);
    thread liftResetThread = thread(lift_reset);

    wait(1400, msec);
    mogo.set(true);
    moveIntake(12);

    // rings 1/2
    chassis.turn_kd = 4.1;
    chassis.turn_settle_error = 3;//1
    chassis.turn_settle_time = 50;//200
    chassis.turn(164);
    chassis.move(15.25);
    wait(300, msec);
    chassis.set_heading_constants(11, 1, 0, 6.5, 0);
    chassis.arc(12, 120);

    // ring 3
    chassis.drive_kd = 10;
    chassis.set_heading_constants(11, 1, 0, 6.5, 0);
    chassis.arc(-20, 180);
    chassis.drive_kd = 8;
    chassis.turn_kd = 3.2;
    chassis.turn_settle_error = 3; 
    chassis.turn_settle_time = 50; 
    chassis.turn(90);
    chassis.drive_settle_error = 1.2; 
    chassis.drive_settle_time = 50; 
    chassis.move(20);

    // rings 4/5
    chassis.turn(48);
    chassis.drive_settle_error = 0.5; 
    chassis.drive_settle_time = 100;
    chassis.drive_timeout = 800;
    chassis.move(30);
    wait(500, msec);
    chassis.move(10, 6);
    wait(500, msec);
    chassis.move(-10, 6);
    wait(500, msec);
    chassis.move(10, 6);

    // chassis.set_drive_constants(12, 1.2, 0, 8, 0); 
    // chassis.set_heading_constants(9.75, 1, 0, 5.5, 0);
    // chassis.arc(25, 119);
        // wait(500, msec);
    // chassis.drive_timeout = 1000;
    // chassis.move(8);

    // ring 3

    
    // corner
    // chassis.move(-15);
    // chassis.turn(68);
    // chassis.move(35, 9);
    // wait(500, msec);
    //chassis.move(10);


    //void move5_5() { chassis.move(5.5); }
}