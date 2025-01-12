#include "vex.h"

// chassis control
#pragma region
void move_chassis(float left, float right) {
  l.spin(fwd, left, volt);
  r.spin(fwd, right, volt);
}

float curve(float x, float scale) {
  if (scale != 0)
    return pow(2.718, (scale * ((abs(x) - 127))) / 1000 ) * x;
  return x;
}

void arcade(float forward, float turn) {
  float left = to_volt(forward + turn);
  float right = to_volt(forward - turn);
  move_chassis(left, right);
}

void arcade(float forward, float turn, bool enable_turn_curve) {
  float left = to_volt(forward + turn);
  float right = to_volt(forward - turn);
  if (enable_turn_curve) curve(right, TURN_CURVE_SCALE);
  move_chassis(left, right);
}

#pragma endregion

// color filters
#pragma region
void filter_ring(int intake_time) {
  wait(intake_time, msec);
  move_intake(-12);
  wait(300, msec);
  move_intake(12);
}

void filter_color(std::string sorted_color) {
  optic.integrationTime(5);
  while (1) {
    optic.setLight(ledState::on);
    optic.setLightPower(100);
    
    if (optic.isNearObject()) {
      // if we are on blue team
      if (sorted_color == "red") {
        if ((optic.hue() > RED_LOWER_LIM) && (optic.hue() < RED_UPPER_LIM)) {
          filter_ring(200);
        }
      }
      // if we are on red team
      else if (sorted_color == "blue") {
        if ((optic.hue() > BLUE_LOWER_LIM) && (optic.hue() < BLUE_UPPER_LIM)) {
          filter_ring(200);
        }
      }
    }
  }
}

void detect_and_stop_ring() {
  while (!optic.isNearObject()) {
    move_intake(12);
    wait(5, msec);
  }
  move_intake(0);
}

void detect_ring() {
  int run_time = 0;
  while (!optic.isNearObject()) {
    if (run_time >= 3000) { // timeout
      break;
    }
    move_intake(12);
    wait(1, msec);
    run_time += 1;
  }
}

void filter_red() { filter_color("red"); }
void filter_blue() { filter_color("blue"); }

#pragma endregion

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

// mogo / doinker
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