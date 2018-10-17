#include "drive.hpp"
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

  // low flag, single cap, then park   CLOSE TILE RED SIDE

  setChassisCurrent(700);
  chassisController.setMaxVelocity(200);
  lift.move_relative(0, 50);
  chassisController.moveDistance(-40_in);
  pros::delay(300);
  chassisController.moveDistance(40_in);
  pros::delay(300);
  chassisController.turnAngle(-85_deg);
  pros::delay(300);
  // // chassisController.forward(-.25);
  // // pros::delay(800);
  // // chassisController.forward(.25);
  // pros::delay(500);
  lift.moveAbsolute(50, 150);
  // intake.moveAbsolute(420, 100);
  lift.moveAbsolute(0, 150);
  chassisController.moveDistance(38_in);
  pros::delay(300);
  // intake.moveAbsolute(555, 100);
  pros::delay(500);
  chassisController.moveDistance(-2_in);
  pros::delay(500);
  chassisController.turnAngle(85_deg);
  pros::delay(300);
  chassisController.moveDistance(-10_in);
  lift.moveAbsolute(100, 150);
  pros::delay(300);
  chassisController.setMaxVelocity(200);
  setChassisCurrent(50000);
  chassisController.moveDistance(65_in);
  chassisController.setMaxVelocity(200);
  setChassisCurrent(50000);

  while (true) {
    robotStats();
    pros::delay(10);
  }
}
