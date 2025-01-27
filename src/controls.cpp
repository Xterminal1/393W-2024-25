#include "vex.h"

void move_chassis(float left, float right) {
  l.spin(fwd, left, volt);
  r.spin(fwd, right, volt);
}

float curve(float i, float scale) {
  if (scale != 0)
    return pow(2.718, (scale * ((abs(i) - 127))) / 1000 ) * i;
  return i;
}

// intake
void move_intake(float volts) { intake.spin(fwd, volts, volt); }

// lift
void move_lift(float position, float vel) {
  lift.setVelocity(vel, pct);
  lift.spinToPosition(position, degrees);
}

// lift controls
void lift_reset() { move_lift(0, 100); }
void lift_grab() { move_lift(115, 100); }
void lift_score() { move_lift(635, 100); }

bool state = false;

void mogo_control() {
  state = !state;
  mogo.set(state);
}

void doinker_control() { 
  state = !state;
  doinker.set(state);
}

// usercontrol main loop
void controls() {
  // chassis
  int forward = controller1.Axis3.position();
  int turn = controller1.Axis1.position();
  //int turn = (abs(x) * x) / 100;
  //int turn = curve(x, 15);
  l.spin(fwd, to_volt(forward + turn), volt);
  r.spin(fwd, to_volt(forward - turn), volt);

  // intake
  if (controller1.ButtonL1.pressing()) {
    move_intake(12);
  } else if (controller1.ButtonL2.pressing()) {
    move_intake(-12);
  } else {
    move_intake(0);
  }

  // lift
  // if (controller1.ButtonUp.pressing()) {
  //   lift.spin(fwd, 6, volt);
  // } else if (controller1.ButtonDown.pressing()) {
  //   lift.spin(fwd, -6, volt);
  // } else if (controller1.ButtonA.pressing()) {
  //   move_lift(0, 100);
  // } else if (controller1.ButtonX.pressing()) {
  //   move_lift(115, 100);
  // } else if (controller1.ButtonY.pressing()) {
  //   move_lift(635, 100);
  // }
  // else {
  //   lift.stop(hold);
  // }
}