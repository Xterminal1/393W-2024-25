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
    std::cout << "lift:           " << lift.position(degrees) << std::endl << std::endl;
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

  telemetry();

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

  int auton = 4;

  if (auton == 0) {
    redLeft();
  } else if (auton == 1) {
    red_right();
  } else if (auton == 2) {
    blue_left(); 
  } else if (auton == 3) {
    blueRight();
  } else if (auton == 4) {
    SKILLS();
  } else if (auton == 5)
    test();
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

void usercontrol(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.setFont(mono60);
  Brain.Screen.setCursor(2.5, 1);
  Brain.Screen.print("393W");   

  bool newL1 = false;
  bool newL2 = false;
  bool newR1 = false;
  bool newR2 = false;

  while (1) {
    
    // // chassis
    // int forward = controller1.Axis3.position();
    // int turn = controller1.Axis1.position();
    // l.spin(fwd, to_volt(forward + turn), volt);
    // r.spin(fwd, to_volt(forward - turn), volt);

    // // intake

    // if (controller1.ButtonL1.pressing()) {
    //   newL1 = true;
    // } else {
    //   newL1 = false;
    // }

    // if (controller1.ButtonL2.pressing()) {
    //   newL2 = true;
    // } else {
    //   newL2 = false;
    // }
    
    // // lift
    // if (((controller1.ButtonL1.pressing() && newL2 || (newL1 && controller1.ButtonL2.pressing())) || ((newL1 && newL2) || (controller1.ButtonL1.pressing()) && (controller1.ButtonL2.pressing())))) {
    //   lift.spin(fwd, 6, volt);
    //   moveIntake(0);
    // // } else if (((controller1.ButtonR1.pressing() && newR2 || (newR1 && controller1.ButtonR2.pressing())) || ((newR1 && newR2) || (controller1.ButtonR1.pressing()) && (controller1.ButtonR2.pressing())))) {
    // //   lift.spin(fwd, -6, volt);
    // //   moveIntake(0);
    // //   doink.set(false);
    // } else if (controller1.ButtonL1.pressing()) {
    //   moveIntake(12);
    // } else if (controller1.ButtonL2.pressing()) {
    //   moveIntake(-12);
    // } else {
    //   moveIntake(0);
    //   lift.stop(hold);
    // } 

    // if (controller1.ButtonA.pressing()) {
    //   moveLift(0, 100);
    // } else if (controller1.ButtonX.pressing()) {
    //   moveLift(115, 100);
    // } else if (controller1.ButtonY.pressing()) {
    //   moveLift(635, 100);
    // }

    controls();

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

  controller1.ButtonA.pressed(lift_reset);
  controller1.ButtonX.pressed(lift_grab);
  controller1.ButtonY.pressed(lift_score);

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}