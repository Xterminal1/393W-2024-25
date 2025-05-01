#include <vex.h>

void red_left_6_ring() {
    std::cout << "AUTON BEGIN" << endl;

    intake.setMaxTorque(100, pct);
    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    // clamp mogo
    auto move_neg_42_6v = []() { chassis.move(-33.5, 5); }; 
    thread move_neg_42_6 = thread(move_neg_42_6v);
    wait(1400, msec);
    mogo.set(true);
    
    // rings 1/2
    chassis.drive_settle_error = 1.2; 
    chassis.drive_settle_time = 50; 
    chassis.turn_kd = 4.1;
    chassis.turn_settle_error = 3;//1
    chassis.turn_settle_time = 50;//200
    chassis.turn(164);
    moveIntake(12);
    chassis.move(14);
    wait(300, msec);
    chassis.set_heading_constants(11, 1, 0, 6.5, 0);
    chassis.arc(15, 120);

    // ring 3
    chassis.drive_kd = 10;
    chassis.set_heading_constants(11, 1, 0, 6.5, 0);
    chassis.arc(-31, 180);
    chassis.drive_kd = 8;
    chassis.turn_kd = 3.2;
    chassis.turn_settle_error = 3; 
    chassis.turn_settle_time = 50; 
    chassis.turn(119);
    chassis.drive_settle_error = 1; 
    chassis.drive_settle_time = 200; 
    chassis.move(20);
}