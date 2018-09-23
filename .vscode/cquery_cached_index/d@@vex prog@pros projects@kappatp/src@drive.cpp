#include "main.h"

Motor *driveR1;

driveR1 = new Motor(MPORT_DRIVE_R1, true, AbstractMotor::gearset::green,
                    AbstractMotor::encoderUnits::degrees);
Motor driveR2(MPORT_DRIVE_R2, true, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveR3(MPORT_DRIVE_R3, true, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);

Motor driveL1(MPORT_DRIVE_L1, false, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveL2(MPORT_DRIVE_L2, false, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);
Motor driveL3(MPORT_DRIVE_L3, false, AbstractMotor::gearset::green,
              AbstractMotor::encoderUnits::degrees);

void powerDrive(int left, int right) {
  driveL1.moveVoltage(left);
  driveL2.moveVoltage(left);
  driveL3.moveVoltage(left);
  driveR1.moveVoltage(right);
  driveR2.moveVoltage(right);
  driveR3.moveVoltage(right);
}

void changeDriveState(tDriveStates driveState) {
  switch (currDriveState) {
  case driveNotRunning:
    powerDrive(0, 0);
    break;
  }
  currDriveState = driveState;
}

void checkDriveState() {
  if ((currRT[leftY] < driveDeadThresh && joystickFalling(rightY)) ||
      (currRT[rightY] < driveDeadThresh && joystickFalling(leftY))) {
    changeDriveState(driveNotRunning);
  } else {
    changeDriveState(driveRunning);
  }
}

void driveTank() { chassis.tank(currRT[leftY], currRT[leftY]); }

/*
void driveArcade() //Arcade Drive Control w/ deadzone threshold
{
  drivePower = currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y];
  turnPower = currJoyRT[E_CONTROLLER_ANALOG_RIGHT_X];
  powerDrive(drivePower + turnPower, drivePower - turnPower);
}
*/

void updateDrive() {
  switch (currDriveState) {
  case driveNotRunning:
    break;

  case driveRunning:
    driveTank();
    break;

  case driveHolding:
    break;
  }
}
