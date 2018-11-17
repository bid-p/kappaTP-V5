#include "main.h"

Controller controller;

ControllerButton abortBtn = ControllerDigital::B;
ControllerButton lockdownBtn = ControllerDigital::X;

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
  pros::lcd::print(4, "Lift Encoder: %i", (int)lift.get_position());
  pros::lcd::print(5, "Intake State: %c | Intake Temp: %i", intakeState,
                   (int)intake.get_temperature());
  pros::lcd::print(6, "Intake Encoder: %i", (int)intake.get_position());
}

void initActTasks() {

  pros::Task intakeActTask(intakeAct, NULL, TASK_PRIORITY_DEFAULT,
                           TASK_STACK_DEPTH_DEFAULT, "Act Intake");

  pros::Task driveActTask(driveAct, NULL, TASK_PRIORITY_DEFAULT,
                          TASK_STACK_DEPTH_DEFAULT, "Act Drive");

  pros::Task liftActTask(liftAct, NULL, TASK_PRIORITY_DEFAULT,
                         TASK_STACK_DEPTH_DEFAULT, "Act Lift");
}
