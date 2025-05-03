#include <vex.h>

void red_left_stake_5_ring() {

    std::cout << "AUTON BEGIN" << endl;

    chassis.turn_kd = 3.8;
    chassis.turn_settle_error = 1;//1
    chassis.turn_settle_time = 200;//200

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
    // auto move_neg_42_6v = []() { chassis.move(-41, 5); }; 
    // thread move_neg_42_6 = thread(move_neg_42_6v);
    chassis.move(-41, 5);
    thread liftResetThread = thread(lift_reset);
    mogo.set(true);
    wait(500, msec);
    moveIntake(12);

    // rings 1/2
    // chassis.drive_settle_error = 1.2; //
    // chassis.drive_settle_time = 50;
    // chassis.turn_settle_error = 3; 
    // chassis.turn_settle_time = 50; 
    // chassis.turn(164);
    // chassis.move(14);
    // wait(300, msec);
    // chassis.set_heading_constants(11, 1, 0, 6.5, 0);
    // chassis.arc(17, 120);

    chassis.drive_settle_error = 1.2; //
    chassis.drive_settle_time = 50;
    chassis.turn_settle_error = 3; 
    chassis.turn_settle_time = 50; 
    chassis.turn(164);
    chassis.set_heading_constants(11, 1, 0, 6.5, 0);
    chassis.arc(31, 120);

    // ring 3
    chassis.drive_kd = 10;
    chassis.set_heading_constants(11, 0.5, 0, 6.5, 0);
    chassis.arc(-29, 180);
    chassis.drive_kd = 8;
    chassis.turn_kd = 3.2;
    chassis.turn_settle_error = 3; 
    chassis.turn_settle_time = 50; 
    chassis.turn(119);
    chassis.drive_settle_error = 1; //1.2
    chassis.drive_settle_time = 200;//50 
    chassis.move(10.5);

    // rings 4/5
    chassis.turn_settle_error = 1;
    chassis.turn_settle_time = 200;
    chassis.turn(59.5);
    moveIntake(0);
    
    chassis.move(40, 6);
    moveIntake(12);
    //thread t_moveToCorner = thread(moveToCorner);
    chassis.move(7, 12);
    
    wait(200, msec);
    chassis.move(-18, 12);
    wait(500, msec);

    chassis.move(17, 12);
    wait(500, msec);
    chassis.arc(-30, 80);

    //wait(300, msec);
    // chassis.move(7, 12);
    // wait(200, msec);
    // chassis.move(-7, 12);
    // wait(200, msec);
    // chassis.move(7, 12);
    // wait(200, msec);
    
    // // ladder touch
    // chassis.arc(-65, 80);

    // // end
    // wait(200, msec);
    // l.stop();
    // r.stop();
    // COLOR_SORT_FILTER_BLUE.interrupt();
}