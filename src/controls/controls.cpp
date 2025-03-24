#include "vex.h"

bool state = false;
bool liftOverride = false;

void macroMogo() { state = !state; mogo.set(state); }
void macroDoink() { state = !state; doink.set(state); }

void macroLiftReset() { thread LIFT_RESET = thread(liftReset); }
void macroLiftLoad() { thread LIFT_LOAD = thread(liftLoad); }
void macroLiftScore() { thread LIFT_SCORE = thread(liftScore); }

void arcade() {
    int forward = controller1.Axis3.position();
    int rate = controller1.Axis1.position();
    int turn = (abs(rate) * rate) / 100;
    l.spin(fwd, to_volt(forward + turn), volt);
    r.spin(fwd, to_volt(forward - turn), volt); 
}

void usercontrol(void) {
    bool newL1 = false; bool newL2 = false; bool newR1 = false; bool newR2 = false;

    l.setStopping(coast); 
    r.setStopping(coast);
    intakePiston.set(false); 

    while (1) {

        // chassis
        arcade();

        // intake fwd
        if (controller1.ButtonL1.pressing()) 
            newL1 = true;
        else 
            newL1 = false;

        // intake rev
        if (controller1.ButtonL2.pressing())
            newL2 = true;
        else
            newL2 = false;

        // lift
        if (!liftOverride) {

            // double press logic
            if (((controller1.ButtonL1.pressing() && newL2) || (newL1 && controller1.ButtonL2.pressing())) ||
                ((newL1 && newL2) || (controller1.ButtonL1.pressing() && controller1.ButtonL2.pressing()))) {
                lift.spin(fwd, 12, volt);
                moveIntake(0);
            } else if (controller1.ButtonL1.pressing()) {
                moveIntake(12);
            } else if (controller1.ButtonL2.pressing()) {
                moveIntake(-12);
            } else {
                moveIntake(0);
                lift.stop(hold);
            }
        }

        wait(20, msec);
    }
}