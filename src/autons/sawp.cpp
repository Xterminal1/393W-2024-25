#include <vex.h>

void red_sawp() {

    // start
    std::cout << "AUTON BEGIN" << endl;
    chassis.turn_kd = 3.8;
    chassis.turn_settle_error = 1;//1
    chassis.turn_settle_time = 200;//200
    intake.setMaxTorque(100, pct);
    thread COLOR_SORT_FILTER_BLUE = thread(filterBlue);

    // preload -> alliance stake
    thread t_liftGrab = thread(lift_grab);
    moveIntake(12);
    
    auto moveToAllyStake = []() { chassis.move(7.5); }; 
    thread t_moveToAllyStake = thread(moveToAllyStake);

    wait(500, msec);
    moveIntake(0);
    moveLift(LIFT_SCORE_POS, 100);
    wait(150, msec);

    // clamp goal 1
    chassis.move(-38, 9);
    thread liftResetThread = thread(lift_reset);
    mogo.set(true);
    wait(500, msec);
    
    // ring 1
    chassis.turn(90);
    moveIntake(12);
}

void blue_sawp() {

}