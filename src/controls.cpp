#include "vex.h"

bool state = false;

void controlMogo() {
  state = !state;
  mogo.set(state);
}

void controlDoink() { 
  state = !state;
  doink.set(state);
}

void controlIntakePiston() {
  state = !state;
  intakePiston.set(state);
}

void arcade() {
  int forward = controller1.Axis3.position();
  int rate = controller1.Axis1.position();
  int turn = (abs(rate) * rate) / 100;
  l.spin(fwd, to_volt(forward + turn), volt);
  r.spin(fwd, to_volt(forward - turn), volt); 
}

// usercontrol main loop
void controls() {
  // chassis
  arcade();

  // intake
  if (controller1.ButtonL1.pressing()) {
    moveIntake(12);
  } else if (controller1.ButtonL2.pressing()) {
    moveIntake(-12);
  } else {
    moveIntake(0);
  }

  // lift
  if (controller1.ButtonB.pressing()) {
    lift.spin(fwd, 6, volt);
  } else {
    lift.stop(hold);
  }
}

