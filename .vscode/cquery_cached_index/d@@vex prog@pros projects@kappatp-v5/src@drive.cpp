#include "main.h"

Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green);
Motor driveL3(MPORT_DRIVE_L3, false, AbstractMotor::gearset::green);
Motor driveR1(MPORT_DRIVE_R1, false, AbstractMotor::gearset::green);
Motor driveR2(MPORT_DRIVE_R2, false, AbstractMotor::gearset::green);
Motor driveR3(MPORT_DRIVE_R3, false, AbstractMotor::gearset::green);

ChassisControllerIntegrated chassisController =
    ChassisControllerFactory::create(
        {MPORT_DRIVE_L1, MPORT_DRIVE_L2, MPORT_DRIVE_L3},    // Left motors
        {-MPORT_DRIVE_R1, -MPORT_DRIVE_R2, -MPORT_DRIVE_R3}, // Right motors
        AbstractMotor::gearset::green,                       // Speed gearset
        {4_in, 9.867_in} // 4 inch wheels, 9.867 inch wheelbase width
    );

ControllerButton driveHoldBtn = controller[ControllerDigital::A];

tDriveStates currDriveState;
char driveState = 'x';

void updateDrive() {
  currDriveState = driveRunning; // driveRunning is default state

  if (driveHoldBtn.changedToPressed()) {
    currDriveState = driveHolding;
  }
}

void driveAct() {
  switch (currDriveState) {
  case driveNotRunning:
    driveState = 'n';
    break;

  case driveRunning:
    driveState = 'r';
    chassisController.setBrakeMode(AbstractMotor::brakeMode::coast);
    chassisController.tank(controller.getAnalog(ControllerAnalog::leftY),
                           controller.getAnalog(ControllerAnalog::rightY),
                           joyDeadband);
    break;

  case driveHolding:
    driveState = 'h';
    chassisController.setBrakeMode(AbstractMotor::brakeMode::hold);
    break;

  case driveCoasting:
    driveState = 'c';
    chassisController.setBrakeMode(AbstractMotor::brakeMode::coast);
    break;

  case driveTurnBraking:
    driveState = 't';
    break;
  }
}
