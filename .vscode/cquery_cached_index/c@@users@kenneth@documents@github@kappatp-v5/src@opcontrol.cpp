#include "main.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  currDriveState = driveNotRunning;
  currIntakeState = intakeNotRunning;
  currLiftState = liftNotRunning;
  while (true) {
    pros::lcd::print(0, "%d %d %d",
                     (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                     (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                     (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);

    updateDrive();
    updateIntake();
    updateLift();

    checkAbortSubsystems();

    pros::lcd::print(0, "Lift State: %c | Lift Temp: %i", liftState,
                     (int)lift.get_temperature());
    pros::lcd::print(1, "Drive State: %c", driveState);
    pros::lcd::print(2, "Intake State:%c", intakeState);

    driveAct();
    intakeAct();
    liftAct();

    pros::delay(10);
  }
}
