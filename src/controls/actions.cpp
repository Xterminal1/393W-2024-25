#include <vex.h>

void moveChassis(float left, float right) {
    l.spin(fwd, left, volt);
    r.spin(fwd, right, volt);
}

void moveIntake(float volts) { intake.spin(fwd, volts, volt); }

void intakeMaxFWD() { moveIntake(12); }
void intakeMaxREV() { moveIntake(-12); }
void intakeStop() { moveIntake(0); }

void moveLift(float position) {
    lift.setVelocity(100, pct);
    lift.spinToPosition(position, deg);
}

void liftReset() { moveLift(0); lift.resetPosition(); }
void liftLoad() { moveLift(120); }
void liftVertical() { moveLift(350); }
void liftScore() { moveLift(647); }
void liftMax() { lift.spin(fwd, 12, volt); }
void liftCoast() { lift.stop(hold); }