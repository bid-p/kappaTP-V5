#include "main.h"
#include <iomanip> // setprecision
#include <sstream> // stringstream

Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green);
Motor driveL3(MPORT_DRIVE_L3, false, AbstractMotor::gearset::green);
Motor driveR1(MPORT_DRIVE_R1, false, AbstractMotor::gearset::green);
Motor driveR2(MPORT_DRIVE_R2, false, AbstractMotor::gearset::green);
Motor driveR3(MPORT_DRIVE_R3, false, AbstractMotor::gearset::green);

const QLength chassisWidth = 9.867_in;

ChassisControllerIntegrated chassisController =
    ChassisControllerFactory::create(
        {MPORT_DRIVE_L1, MPORT_DRIVE_L2, MPORT_DRIVE_L3},    // Left motors
        {-MPORT_DRIVE_R1, -MPORT_DRIVE_R2, -MPORT_DRIVE_R3}, // Right motors
        AbstractMotor::gearset::green,                       // Speed gearset
        {4.125_in, chassisWidth} // 4 inch wheels, 9.867 inch wheelbase width
    );

AsyncMotionProfileController profileController =
    AsyncControllerFactory::motionProfile(1.09, 4.0,
                                          10.0, // maxvel, accel, max jerk
                                          chassisController);

tDriveStates currDriveState;
char driveState = 'D';

pros::Mutex driveMutex;

void updateDrive() {
  // driveMutex.take(10);

  if (abs(controller.getAnalog(ControllerAnalog::leftY)) > joyDeadband ||
      abs(controller.getAnalog(ControllerAnalog::rightY)) > joyDeadband) {
    currDriveState = driveRunning;
    driveState = 'r';
  } else {
    currDriveState = driveNotRunning;
    driveState = 'x';
  }

  // driveMutex.give();
}

void driveAct(void *) {
  while (true) {
    // driveMutex.take(500);

    switch (currDriveState) {
    case driveNotRunning:
      chassisController.setBrakeMode(AbstractMotor::brakeMode::coast);
      chassisController.tank(0, 0, 0);
      break;

    case driveRunning:
      chassisController.setBrakeMode(AbstractMotor::brakeMode::coast);
      chassisController.tank(controller.getAnalog(ControllerAnalog::leftY),
                             controller.getAnalog(ControllerAnalog::rightY),
                             joyDeadband);
      currDriveState = driveNotRunning;
      break;

      // driveMutex.give();
    }
    pros::delay(10);
  }
}
