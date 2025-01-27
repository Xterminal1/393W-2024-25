#include "vex.h"

void filter_ring() {
  wait(300, msec);
  move_intake(-12);
  wait(300, msec);
  move_intake(12);
}

void get_ring(std::string targetColor) {
  optic.integrationTime(5);
  while (1) {
    optic.setLight(ledState::on);
    optic.setLightPower(100);
  
    
    if (optic.isNearObject()) {
      // if we are on blue team
      if (targetColor == "red") {
        if ((optic.hue() > RED_LOWER_LIM) && (optic.hue() < RED_UPPER_LIM)) {
          filter_ring();
        }
      }
      // if we are on red team
      else if (targetColor == "blue") {
        if ((optic.hue() > BLUE_LOWER_LIM) && (optic.hue() < BLUE_UPPER_LIM)) {
          filter_ring();
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

void filter_red() { get_ring("red"); }
void filter_blue() { get_ring("blue"); }