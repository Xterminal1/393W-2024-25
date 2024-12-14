#include "vex.h"

// chassis control
#pragma region
void moveChassis(float left, float right) {
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
  moveChassis(left, right);
}

void arcade(float forward, float turn, bool enableTurnCurve) {
  float left = to_volt(forward + turn);
  float right = to_volt(forward - turn);
  if (enableTurnCurve) curve(right, 15);
  moveChassis(left, right);
}

#pragma endregion

// color filters
#pragma region
void filterRing(int intakeTime) {
  wait(intakeTime, msec);
  moveIntake(-12);
  wait(300, msec);
  moveIntake(12);
}

void filterColor(string sortedColor) {
  const int rl1 = 8;//350
  const int rl2 = 15;//10
  const int bl1 = 210;//220
  const int bl2 = 230;//250
  
  optic.integrationTime(5);
  
  while (true) {

    optic.setLight(ledState::on);
    optic.setLightPower(100);
    
    if (optic.isNearObject()) {
      
      // if we are on blue team
      if (sortedColor == "red") {
        if ((optic.hue() > rl1) && (optic.hue() < rl2)) {
          filterRing(200);
        }
      }

      // if we are on red team
      else if (sortedColor == "blue") {
        if ((optic.hue() > bl1) && (optic.hue() < bl2)) {
          filterRing(200);
        }
      }
    }
  }
}

void detectStopRing() {
  while (!optic.isNearObject()) {
    moveIntake(12);
    wait(5, msec);
  }
  moveIntake(0);
}

void detectRing() {
  int rl1 = 8;
  int rl2 = 15;
  int count = 0;
  while (!optic.isNearObject()) {
    if (count >= 3000) { // timeout
      break;
    }
    moveIntake(12);
    wait(1, msec);
    count += 1;
  }
}

void filterRed() { filterColor("red"); }
void filterBlue() { filterColor("blue"); }

#pragma endregion

// intake
void moveIntake(float volts) { intake.spin(fwd, volts, volt); }

// lift
void moveLift(float position, float vel) {
  lift.setVelocity(vel, pct);
  lift.spinTo(position, deg);
}

// lift controls
void liftReset() { moveLift(0, 100); }
void liftGrab() { moveLift(90, 100); }
void liftScore() { moveLift(450, 100); }

// mogo / doinker
bool state = false;

void mogoControl() {
  state = !state;
  mogo.set(state);
}

void doinkerControl() { 
  state = !state;
  mogo.set(state);
}

// usercontrol main loop
void controls() {
  // chassis
  int forward = controller1.Axis3.position();
  int turn = controller1.Axis1.position();
  arcade(forward, turn, true);

  // intake
  if (controller1.ButtonL1.pressing()) {
    moveIntake(12);
  } else if (controller1.ButtonL2.pressing()) {
    moveIntake(-12);
  } else {
    moveIntake(0);
  }
}