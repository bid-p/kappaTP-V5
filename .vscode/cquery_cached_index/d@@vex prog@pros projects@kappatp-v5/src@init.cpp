#include "main.h"

Controller controller;

ControllerButton abortBtn = ControllerDigital::B;

const double joyDeadband = .08;

void checkAbortSubsystems() {
  if (abortBtn.changedToPressed()) {
    currDriveState = driveNotRunning;
    currIntakeState = intakeNotRunning;
    currLiftState = liftNotRunning;
  }
}
