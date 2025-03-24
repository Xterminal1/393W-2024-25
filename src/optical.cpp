#include "vex.h"

void filterRing(float intakeTime) {
  wait(intakeTime, msec);//160
  moveIntake(-12);
  wait(100, msec);
  moveIntake(12);
}

void getRing(std::string targetColor, float intakeTime) {
  opticalSensor.integrationTime(5);
  while (1) {
    opticalSensor.setLight(ledState::on);
    opticalSensor.setLightPower(100);
  
    
    if (opticalSensor.isNearObject()) {
      // if we are on blue team
      if (targetColor == "red") {
        if ((opticalSensor.hue() > RED_LOWER_LIM) && (opticalSensor.hue() < RED_UPPER_LIM)) {
          filterRing(intakeTime);
        }
      }
      // if we are on red team
      else if (targetColor == "blue") {
        if ((opticalSensor.hue() > BLUE_LOWER_LIM) && (opticalSensor.hue() < BLUE_UPPER_LIM)) {
          filterRing(intakeTime);
        }
      }
    }
  }
}

void detectStopRing() {
  while (!opticalSensor.isNearObject()) {
    moveIntake(12);
    wait(5, msec);
  }
  moveIntake(0);
}

void detectRing() {
  int run_time = 0;
  while (!opticalSensor.isNearObject()) {
    if (run_time >= 3000) { // timeout
      break;
    }
    moveIntake(12);
    wait(1, msec);
    run_time += 1;
  }
}

void detectRedRing() {
  int run_time = 0;
  while (!((opticalSensor.hue() > RED_LOWER_LIM) && (opticalSensor.hue() < RED_UPPER_LIM))) {
    // if (run_time >= 3000) { // timeout
    //   break;
    // }
    moveIntake(12);
    //wait(1, msec);
    //run_time += 1;
  }
}

void filterRed() { getRing("red", 100); }
void filterBlue() { getRing("blue", 100); }
void filterBlueSlow() { getRing("blue", 370); }