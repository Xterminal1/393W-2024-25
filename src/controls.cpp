#include "vex.h"

void move_chassis(float left, float right) {
  l.spin(fwd, left, volt);
  r.spin(fwd, right, volt);
}

float curve(float i, float scale) {
  if (scale != 0)
    return (pow(2.718, (scale * ((std::fabs(x) - 100))) / 1000 ) * i);
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
  //int turn = (pow(i, 1.5)) / 100;
  //int turn = curve(i, 5.1);
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

  // if (((con.get_digital(E_CONTROLLER_DIGITAL_R1) && NEWR2) || (NEWR1 && con.get_digital(E_CONTROLLER_DIGITAL_R2))) || ((NEWR1 && NEWR2) || (con.get_digital(E_CONTROLLER_DIGITAL_R1) && con.get_digital(E_CONTROLLER_DIGITAL_R2)))){
  //     //Double Press action
  //     INTAKE.move(127);
  //     HOOKS.move(-95);
  //   // HOOKS.move(-127);
  //   } else if  (con.get_digital(E_CONTROLLER_DIGITAL_R1)) {
	// 		INTAKE.move(-127);
  //     HOOKS.move(-127);
	// 	} else if (con.get_digital(E_CONTROLLER_DIGITAL_R2)) {
	// 		INTAKE.move(127);
  //    HOOKS.move(127);
	// 	} else {
	// 		INTAKE.move(0);
  //     HOOKS.move(0);
	// 	}



  //thread tc = thread(filter_red);

  // lift
  if (controller1.ButtonUp.pressing()) {
    lift.spin(fwd, 6, volt);
  } else if (controller1.ButtonDown.pressing()) {
    lift.spin(fwd, -6, volt);
  } else if (controller1.ButtonA.pressing()) {
    move_lift(0, 100);
  } else if (controller1.ButtonX.pressing()) {
    move_lift(115, 100);
  } else if (controller1.ButtonY.pressing()) {
    move_lift(635, 100);
  }
  else {
    lift.stop(hold);
  }
}