#include "vex.h"

void defaultConstants() {
    chassis.setLateralPID(12, 1.2, 0, 8, 0);
    chassis.setHeadingPID(6, .4, 0, 1, 0);
    chassis.setAngularPID(12, 0.4, 0.03, 3.2, 15);
    chassis.setSwingPID(12, 1, 0.01, 6, 0);

    chassis.setLateralExits(1.5, 300, 4000);
    chassis.setAngularExits(1, 300, 3000);
    chassis.setSwingExits(1, 200, 3000);
}