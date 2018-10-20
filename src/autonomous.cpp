#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  pros::lcd::print(0, "%d %d %d",
                   (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
                   (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
                   (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
  pros::lcd::print(0, "Autonomous:");

  // executeRedCloseAuton();
  // executeRedFarAuton();
  // executeBlueCloseAuton();
  // executeBlueFarAuton();
  executeRedFarParkAuton();
  // executeBlueFarParkAuton();

  while (true) {
    robotStats();
    pros::delay(10);
  }
}
