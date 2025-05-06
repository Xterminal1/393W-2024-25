#include "vex.h"

using namespace vex;
competition Competition;

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

int auton = 0;

void telemetry() {
  while (1) {
    float pos = (chassis.get_right_position_in() + chassis.get_left_position_in()) / 2;
    std::cout << "position:         " << pos << std::endl;
    std::cout << "heading:          " << chassis.get_absolute_heading() << std::endl;
    std::cout << "drive:            " << l.voltage() << std::endl;
    std::cout << "intake:           " << intake.temperature(celsius) << std::endl << std::endl;
    //std::cout << "velocity:         " << (l.voltage() + r.voltage()) / 2 << std::endl << std::endl;
    //std::cout << "output:           " << chassis.
    //std::cout << "drive temp:       " << l.temperature() << std::endl;
    //std::cout << "intake temp:      " << intake.temperature(celsius) << std::endl;
    //std::cout << "intake vel:       " << intake.voltage() << std::endl;
    //std::cout << "lift position:    " << lift.position(deg) << std::endl;
    wait(500, msec);
  }
}

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  //telemetry();

  imu.calibrate(3000);
  wait(3000, msec);

  optic.setLight(ledState::on);
  optic.setLightPower(100);
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  l.resetPosition();
  r.resetPosition();
  lift.resetPosition();
  imu.resetHeading();
  imu.resetRotation();
  rotationSensor.resetPosition();

  int auton = 6;

  if (auton == -1) {
    
    thread t_filter = thread(filterBlue);
    mogo.set(true);
    wait(500, msec);
    moveIntake(12);

  } else if (auton == 0) {
    red_left_1_5_ladder();
  } else if (auton == 1) {
    red_left_6_ring();
  } else if (auton == 2) {
    blue_right_1_5_ladder();
  } else if (auton == 3) {
    red_left_1_6_elims();
  } else if (auton == 4) {
    blue_left_5_ladder();
  } else if (auton == 5) {
    red_right_5_ladder();
  } else if (auton == 6) {
    red_sawp();
  }
  // } else if (auton == 7) 
  //   SKILLS();S
  // }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

float liftRotation = rotationSensor.angle(deg);

bool liftOverride = false;

void moveLiftTo(float position) {

  lift.setVelocity(100, pct);

  liftOverride = true;

  //lift.setVelocity(100, percent);
  float error = position - liftRotation;
  lift.spinToPosition(error, degrees);

  lift.stop(hold);
  liftOverride = false;
}

void lr() { moveLiftTo(0); rotationSensor.resetPosition(); }
void lg() { moveLiftTo(135); }
void ls() { moveLiftTo(647); }

void liftResetMacro() { thread liftReset = thread(lr); }
void liftGrabMacro() { thread liftGrab = thread(lg); }
void liftScoreMacro() { thread liftScore = thread(ls); }

void usercontrol(void) {
  bool newL1 = false; bool newL2 = false;

  l.setStopping(coast); 
  r.setStopping(coast);
  intakePiston.set(false);

  while (1) {

    // chassis
    arcade();

    // intake fwd
    if (controller1.ButtonL1.pressing()) 
      newL1 = true;
    else 
      newL1 = false;

    // intake rev
    if (controller1.ButtonL2.pressing())
      newL2 = true;
    else
      newL2 = false;
    
    // lift
    if (!liftOverride) {

      if (((controller1.ButtonL1.pressing() && newL2) || (newL1 && controller1.ButtonL2.pressing())) ||
          ((newL1 && newL2) || (controller1.ButtonL1.pressing() && controller1.ButtonL2.pressing()))) {
        lift.spin(fwd, 12, volt);
        moveIntake(0);
      } else if (controller1.ButtonL1.pressing()) {
        moveIntake(12);
      } else if (controller1.ButtonL2.pressing()) {
        moveIntake(-12);
      } else {
        moveIntake(0);
        lift.stop(hold);
      }
    }

    wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  
  controller1.ButtonR1.pressed(controlMogo);
  controller1.ButtonR2.pressed(controlDoink);
  controller1.ButtonDown.pressed(controlIntakePiston);

  controller1.ButtonA.pressed(liftResetMacro);
  controller1.ButtonX.pressed(liftGrabMacro);
  controller1.ButtonY.pressed(liftScoreMacro);

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}