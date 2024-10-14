#include "vex.h"

using namespace vex;
competition Competition;

#pragma region
/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors. In VEXcode Pro V5, you can do this using the graphical          */
/*  configurer port icon at the top right. In the VSCode extension, you'll   */
/*  need to go to robot-config.cpp and robot-config.h and create the         */
/*  motors yourself by following the style shown. All motors must be         */
/*  properly reversed, meaning the drive should drive forward when all       */
/*  motors spin forward.                                                     */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your motors.                                     */
/*---------------------------------------------------------------------------*/

Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(lf, lm, lb),

//Right Motors:
motor_group(rf, rm, rb),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT9,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);
#pragma endregion

/**
 * Function before autonomous. It prints the current auton number on the screen
 * and tapping the screen cycles the selected auton by 1. Add anything else you
 * may need, like resetting pneumatic components. You can rename these autons to
 * be more descriptive, if you like.
 */

int auton = 0;

void pre_auton() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();

  // calibration of IMU
  imu.calibrate(3000);
  wait(3000, msec);

  // battery check
  int battery = Brain.Battery.capacity();
  if (battery > 75) {
    Brain.Screen.clearScreen(green);
    Brain.Screen.setFillColor(green);
  } else if (battery > 50) {
    Brain.Screen.clearScreen(yellow);
    Brain.Screen.setFillColor(yellow);
  } else if (battery > 25) {
    Brain.Screen.clearScreen(orange);
    Brain.Screen.setFillColor(orange);
  } else {
    Brain.Screen.clearScreen(red);
    Brain.Screen.setFillColor(red);
    
  }

  Brain.Screen.printAt(5, 20, "393W");
  Brain.Screen.printAt(5, 40, "Battery: %d", battery);

  // auton selector
  Brain.Screen.printAt(5, 60, "");
  Brain.Screen.printAt(5, 80, "Selected auton:");
  Brain.Screen.setFont(mono30);

  while (true) {
    if (limit_switch.pressing()) {
      auton++;
      wait(200, msec);
    }
    
    if (auton == 0) {
      Brain.Screen.printAt(5, 110, "Auton 1: Red Left    ");
    } else if (auton == 1) {
      Brain.Screen.printAt(5, 110, "Auton 2: Red Right   ");
    } else if (auton == 2) {
      Brain.Screen.printAt(5, 110, "Auton 3: Blue Left   ");
    } else if (auton == 3) {
      Brain.Screen.printAt(5, 110, "Auton 4: Blue Right  ");
    } else if (auton == 4) {
      Brain.Screen.printAt(5, 110, "Auton 5: Skills      ");
    } else if (auton == 5) {
      auton = 0;
    }

  }
}

/**
 * Auton function, which runs the selected auton. Case 0 is the default,
 * and will run in the brain screen goes untouched during preauton. Replace
 * drive_test(), for example, with your own auton function you created in
 * autons.cpp and declared in autons.h.
 */

void autonomous(void) {
  imu.resetHeading();
  imu.resetRotation();

  if (auton == 0) {

  } else if (auton == 1) {

  } else if (auton == 2) {

  } else if (auton == 3) {

  } else if (auton == 4) {

  } else if (auton == 5) {

  } else if (auton == 6) {
  
  }
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
  // User control code here, inside the loop
  int time = 0;
  Controller.Screen.clearScreen();
  while (1) {
    controls();

    // motor temperature printing
    double chassis_temperature = (lf.temperature(celsius) + lm.temperature(celsius) + lb.temperature(celsius) + 
                                  rf.temperature(celsius) + rm.temperature(celsius) + rb.temperature(celsius)) / 6;
    if (time % 100 == 0) {
      Controller.Screen.setCursor(0, 0);
      Controller.Screen.print("DRIVE: %f", chassis_temperature);
      Controller.Screen.newLine();
      Controller.Screen.print("INTAKE %f", intake.temperature(celsius));
      Controller.Screen.newLine();
      Controller.Screen.print("LIFT %f", intake.temperature(celsius));
    }
    
    time ++;
    wait(1, msec);  // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

bool toggle_mogo = false;
bool toggle_doinker = false;

void macro_mogo() {
  toggle_mogo = !toggle_mogo;
  mogo.set(toggle_mogo);
}

void macro_doinker() {
  toggle_doinker = !toggle_doinker;
  doinker.set(toggle_doinker);
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Controller.ButtonR1.pressed(macro_mogo);
  Controller.ButtonR2.pressed(macro_doinker);

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  //initialize();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
