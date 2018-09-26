#include "main.h"

Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green);
Motor driveL3(MPORT_DRIVE_L3, false, AbstractMotor::gearset::green);
Motor driveR1(MPORT_DRIVE_R1, true, AbstractMotor::gearset::green);
Motor driveR2(MPORT_DRIVE_R2, true, AbstractMotor::gearset::green);
Motor driveR3(MPORT_DRIVE_R3, true, AbstractMotor::gearset::green);

ChassisControllerIntegrated chassisController =
    ChassisControllerFactory::create(
        {-MPORT_DRIVE_L1, -MPORT_DRIVE_L2, -MPORT_DRIVE_L3}, // Left motors
        {MPORT_DRIVE_R1, MPORT_DRIVE_R2, MPORT_DRIVE_R2},    // Right motors
        AbstractMotor::gearset::green,                       // Speed gearset
        {4_in, 12.5_in} // 4 inch wheels, 12.5 inch wheelbase width
    );

ControllerButton driveHoldBtn = ControllerDigital::A;

tDriveStates currDriveState;

void updateDrive() {
  currDriveState = driveRunning; // driveRunning is default state

  if (driveHoldBtn.changedToPressed()) {
    currDriveState = driveHolding;
  }
}

void driveAct() {
  switch (currDriveState) {
  case driveNotRunning:
    break;

  case driveRunning:
    chassisController.setBrakeMode(AbstractMotor::brakeMode::brake);
    chassisController.tank(controller.getAnalog(ControllerAnalog::leftY),
                           controller.getAnalog(ControllerAnalog::rightY),
                           joyDeadband);
    break;

  case driveHolding:
    chassisController.setBrakeMode(AbstractMotor::brakeMode::hold);
    break;

  case driveCoasting:
    chassisController.setBrakeMode(AbstractMotor::brakeMode::coast);
    break;

  case driveTurnBraking:
    break;
  }
}
