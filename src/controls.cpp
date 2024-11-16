#include "vex.h"

void moveIntake(int vel) { intake.spin(fwd, vel, volt); }

void moveLift(int pos, int vel) {
    lift.setVelocity(vel, percent);
    lift.spinTo(pos, deg);
}

int resetVel = 80;
int grabPos = 60;
int grabVel = 80;
int scorePos = 450;
int scoreVel = 100;

void resetLift() { moveLift(0, resetVel); }
void liftGrab() { moveLift(grabPos, grabVel); }
void liftScore() { moveLift(scorePos, scoreVel); }

bool state = false;

void controlMogo() {
    state = !state;
    mogo.set(state);
}

void controlDoinker() {
    state = !state;
    doinker.set(state);
}

void arcade() {
    int forward = controller1.Axis3.position();
    int turn = controller1.Axis1.position();
    l.spin(fwd, to_volt(forward + turn), volt);
    r.spin(fwd, to_volt(forward - turn), volt);
}

void controls() {
    // chassis
    arcade();

    // intake
    if (controller1.ButtonL1.pressing()) 
        moveIntake(12);
    else if (controller1.ButtonL2.pressing())
        moveIntake(-12);
    else
        moveIntake(0);

}