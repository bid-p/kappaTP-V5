#include "main.h"

Controller controller;

ControllerButton abortBtn = ControllerDigital::B;

const double joyDeadband = .08;

void checkAbortSubsystems() {
  if (abortBtn.changedToPressed()) {
    currDriveState = driveNotRunning;
    currIntakeState = intakeNotRunning;
    currLiftState = liftNotRunning;
    driveState = 'x';
    liftState = 'x';
    intakeState = 'x';
  }
}

void robotStats() {
  pros::lcd::print(1, "Drive State: %c | Drive Temp: %i", driveState,
                   (int)driveR1.get_temperature());
  pros::lcd::print(2, "DL Value: %i, DR Value: %i", (int)driveL2.get_position(),
                   (int)driveR2.get_position());
  pros::lcd::print(3, "Lift State: %c | Lift Temp: %i", liftState,
                   (int)lift.get_temperature());
  pros::lcd::print(4, "Lift POT: %i | Lift Encoder: %i",
                   liftPOT.get_value_calibrated(), (int)lift.get_position());
  pros::lcd::print(5, "Intake State: %c | Intake Temp: %i", intakeState,
                   (int)intake.get_temperature());
  pros::lcd::print(6, "Intake Encoder: %i", (int)intake.get_position());

  pros::delay(10);
}
