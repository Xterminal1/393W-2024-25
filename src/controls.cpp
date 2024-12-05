#include "vex.h"

void moveIntake(int vel) { intake.spin(fwd, vel, volt); }

void moveLift(int pos, int vel) {
    lift.setVelocity(vel, percent);
    lift.spinTo(pos, deg);
}

void resetLift() { moveLift(0, 100); }
void liftGrab() { moveLift(90, 100); }
void liftScore() { moveLift(450, 100); }

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


void sort_ring(int intake_time) {
  wait(intake_time, msec);
  moveIntake(-12);
  wait(300, msec);
  moveIntake(12);
}

//200, 500

void color_sort(std::string filter_color) {
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
      if (filter_color == "red") {
        if ((optic.hue() > rl1) && (optic.hue() < rl2)) {
          sort_ring(200);
        }
      }

      // if we are on red team
      else if (filter_color == "blue") {
        if ((optic.hue() > bl1) && (optic.hue() < bl2)) {
          sort_ring(200);
        }
      }
    }
  }
}

void filterRed() { color_sort("red"); }
void filterBlue() { color_sort("blue"); }

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

