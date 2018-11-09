#include "main.h"

void initRedCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "Back Hit Flag");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{45_in, 0_ft, 0_deg}},
      "Return From Flag Hit");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back From Cap");

  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Back");

  genTurnPath(90_deg);
}

void executeRedCloseAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  profileController.linearReverse();
  profileController.setTarget("Back Hit Flag");
  profileController.waitUntilSettled();

  profileController.linearForward();
  profileController.setTarget("Return From Flag Hit");
  profileController.waitUntilSettled();

  profileController.turnLeft();
  profileController.setTarget("Turn 90.0");
  profileController.waitUntilSettled();

  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // profileController.setTarget("Closer To Cap");
  // profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  profileController.turnRight();
  profileController.setTarget("Turn 90.0");
  profileController.waitUntilSettled();

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  // profileController.reverse();
  // profileController.setTarget("Back");
  // profileController.waitUntilSettled();

  // profileController.setTarget("P");
  // profileController.waitUntilSettled();

  intake.moveAbsolute(420, 200);
}
//
//
//
//
//
//
//
//
//
//
//
//

void initRedFarAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{2_in, 0_in, 0_deg}}, "Center");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{24_in, -40_in, -80_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back From Cap");
}

void executeRedFarAuton() {

  intake.moveAbsolute(-50, 100);
  lift.moveAbsolute(-100, 75);
  intake.moveAbsolute(555, 200);

  // profileController.setTarget("Center");
  // profileController.waitUntilSettled();
  //
  // chassisController.turnAngle(-95._deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  pros::delay(500);
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  intake.moveAbsolute(420, 200);
}
//
//
//
//
//
//
//
//
//
//
void initBlueCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "Back Hit Flag");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{45_in, 0_ft, 0_deg}},
      "Return From Flag Hit");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back From Cap");

  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Back");
}

void executeBlueCloseAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  profileController.linearReverse();
  profileController.setTarget("Back Hit Flag");
  profileController.waitUntilSettled();

  profileController.setTarget("Return From Flag Hit");
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // profileController.setTarget("Closer To Cap");
  // profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  // profileController.reverse();
  // profileController.setTarget("Back");
  // profileController.waitUntilSettled();

  // profileController.setTarget("P");
  // profileController.waitUntilSettled();

  intake.moveAbsolute(420, 200);
}

void initBlueFarAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{2_in, 0_ft, 0_deg}}, "Center");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back From Cap");
}

void executeBlueFarAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);
  intake.moveAbsolute(555, 200);

  // profileController.setTarget("Center");
  // profileController.waitUntilSettled();
  //
  // chassisController.turnAngle(-95._deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  pros::delay(500);
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  profileController.linearReverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  intake.moveAbsolute(420, 200);
}

void initRedFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{34_in, 0_ft, 0_deg}}, "Move");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back");
}

void executeRedFarParkAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-60, 75);
  intake.moveAbsolute(555, 200);

  // profileController.setTarget("Center");
  // profileController.waitUntilSettled();
  //
  // chassisController.turnAngle(-95._deg);
  profileController.setTarget("Move");
  profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  // profileController.reverse();
  // profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  pros::delay(500);
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.linearReverse();
  profileController.setTarget("Back");
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  intake.moveAbsolute(420, 200);
}

void initBlueFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{34_in, 0_ft, 0_deg}}, "Move");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back");
}

void executeBlueFarParkAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-60, 75);
  intake.moveAbsolute(555, 200);

  // profileController.setTarget("Center");
  // profileController.waitUntilSettled();
  //
  // chassisController.turnAngle(-95._deg);
  profileController.setTarget("Move");
  profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  // profileController.reverse();
  // profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  pros::delay(500);
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  profileController.linearReverse();
  profileController.setTarget("Back");
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  intake.moveAbsolute(420, 200);
}
