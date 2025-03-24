#include "vex.h"

using namespace vex;
using namespace std;
competition Competition;

int auton = 0;

void telemetry() {
    while (1) {
        float pos = (chassis.get_right_position_in() + chassis.get_left_position_in()) / 2;
        cout << "position:         " << pos << endl;
        cout << "heading:          " << chassis.get_absolute_heading() << endl;
        cout << "drive:            " << l.voltage() << endl;
        cout << "intake:           " << intake.temperature(celsius) << endl << endl;
        //std::cout << "velocity:         " << (l.voltage() + r.voltage()) / 2 << std::endl << std::endl;
        //std::cout << "output:           " << chassis.
        //std::cout << "drive temp:       " << l.temperature() << std::endl;
        //std::cout << "intake temp:      " << intake.temperature(celsius) << std::endl;
        //std::cout << "intake vel:       " << intake.voltage() << std::endl;
        //std::cout << "lift position:    " << lift.position(deg) << std::endl;
        wait(500, msec);
    }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
    l.resetPosition();
    r.resetPosition();
    lift.resetPosition();
    imu.resetHeading();
    imu.resetRotation();
    rotationSensor.resetPosition();
    int auton = 3;

    if (auton == 0) {
        RED_LEFT();
    } else if (auton == 1) {
        RED_RIGHT();
    } else if (auton == 2) {
        BLUE_LEFT();
    } else if (auton == 3) {
        BLUE_RIGHT();
    } else if (auton == 4) {
        RED_SOLO_AWP();
    } else if (auton == 5) {
        BLUE_SOLO_AWP();
    } else if (auton == 6) {
        SKILLS();
    }
    // } else if (auton == 7) {
    //   SKILLS();S
    // }
}

int main() {
    controller1.ButtonR1.pressed(macroMogo);
    controller1.ButtonR2.pressed(macroDoink);
    controller1.ButtonA.pressed(macroLiftReset);
    controller1.ButtonX.pressed(macroLiftLoad);
    controller1.ButtonY.pressed(macroLiftScore);

    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);

    vexcodeInit();

    //telemetry();
    imu.calibrate(3000);
    wait(3000, msec);

    l.resetPosition();
    r.resetPosition();
    lift.resetPosition();
    
    imu.resetHeading();
    imu.resetRotation();
    rotationSensor.resetPosition();

    opticalSensor.setLight(ledState::on);
    opticalSensor.setLightPower(100);

    defaultConstants();
    
    // Prevent main from exiting with an infinite loop.
    while (true) {
        wait(100, msec);
    }
}