#include "main.h"

void initRedCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{43_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{5_in, 0_ft, 0_deg}}, "D");
}

void executeRedCloseAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(0, 100);

  profileController.setTarget("A", true);
  profileController.waitUntilSettled();

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  chassisController.turnAngleAsync(-90_deg);

  lift.moveAbsolute(-20, 100);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  chassisController.turnAngleAsync(90_deg);

  chassisController.moveDistance(-33_in);
}

//
//

void initBlueCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{43_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{5_in, 0_ft, 0_deg}}, "D");
}

void executeBlueCloseAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(0, 100);

  profileController.setTarget("A", true);
  profileController.waitUntilSettled();

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  chassisController.turnAngleAsync(90_deg);

  lift.moveAbsolute(-20, 100);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  chassisController.turnAngleAsync(-90_deg);

  chassisController.moveDistance(-33_in);
}

//
//

void initRedFarAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{5_in, 0_ft, 0_deg}}, "B");
}

void executeRedFarAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(-20, 100);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  intake.moveAbsolute(-225, 100);
  // lift.moveAbsolute(100, 100);

  pros::delay(500);

  // profileController.turnAngle("Turn 90", 1);
  chassisController.turnAngle(90_deg);
  intake.moveAbsolute(-100, 100);

  // profileController.setTarget("Back", true);
  // profileController.waitUntilSettled();

  chassisController.moveDistance(-33_in);
}

//
//

void initBlueFarAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{5_in, 0_ft, 0_deg}}, "B");
}

void executeBlueFarAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(-20, 100);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  intake.moveAbsolute(-225, 100);
  // lift.moveAbsolute(100, 100);

  pros::delay(500);

  // profileController.turnAngle("Turn 90", 1);
  chassisController.turnAngle(-90_deg);
  intake.moveAbsolute(-100, 100);

  // profileController.setTarget("Back", true);
  // profileController.waitUntilSettled();

  chassisController.moveDistance(-33_in);
}

//
//

void initRedFar2Auton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{-7_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{18_in, 0_ft, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{-13_in, 0_ft, 0_deg}}, "D");
}

void executeRedFar2Auton() {

  intake.moveAbsolute(-270, 100); // Assumes 100 is the value where the extended
  pros::delay(500);
  lift.moveAbsolute(-20, 100); // lets say 50 is the flat floor value

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  chassisController.turnAngle(61_deg);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  intake.moveAbsolute(-80, 100); // Lets say 30 is the intake upflip value
  pros::delay(200);
  intake.moveAbsolute(-270, 50); // Return to flat value

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  chassisController.turnAngle(29_deg);
  intake.moveAbsolute(-225, 100);

  chassisController.moveDistance(-40_in); // park
}

//
//

void initBlueFar2Auton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{-7_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{18_in, 0_ft, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{-13_in, 0_ft, 0_deg}}, "D");
}

void executeBlueFar2Auton() {
  intake.moveAbsolute(-270, 100); // Assumes 100 is the value where the extended
  pros::delay(500);
  lift.moveAbsolute(-20, 100); // lets say 50 is the flat floor value

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  chassisController.turnAngle(-61_deg);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  intake.moveAbsolute(-80, 100); // Lets say 30 is the intake upflip value
  pros::delay(200);
  intake.moveAbsolute(-270, 50); // Return to flat value

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  chassisController.turnAngle(-29_deg);
  intake.moveAbsolute(-225, 100);

  chassisController.moveDistance(-40_in); // park
}

//
//

void initRedFarParkAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{35_in, 0_ft, 0_deg}}, "A");
}

void executeRedFarParkAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(-20, 100);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  intake.moveAbsolute(-225, 100);

  chassisController.turnAngle(90_deg);
  intake.moveAbsolute(-100, 100);

  chassisController.moveDistance(-33_in);
}

//
//

void initBlueFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{35_in, 0_ft, 0_deg}}, "A");
}

void executeBlueFarParkAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(-20, 100);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  intake.moveAbsolute(-225, 100);

  chassisController.turnAngle(-90_deg);
  intake.moveAbsolute(-100, 100);

  chassisController.moveDistance(-33_in);
}
