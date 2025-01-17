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
}

void executeRedCloseAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  profileController.setTarget("Back Hit Flag", true);
  profileController.waitUntilSettled();

  profileController.setTarget("Return From Flag Hit");
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // profileController.setTarget("Closer To Cap");
  // profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.setTarget("Back From Cap", true);
  profileController.waitUntilSettled();

  // profileController.turnAngle("Turn 90", 1); // right turn 90
  chassisController.turnAngle(90_deg);

  profileController.setTarget("Back From Cap", true);
  lift.moveAbsolute(125, 75);
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  // profileController.reverse();
  // profileController.setTarget("Back");
  // profileController.waitUntilSettled();

  // profileController.setTarget("P");
  // profileController.waitUntilSettled();
}

//
//

void initRedFarAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{0_in, 44_in, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{0_in, 8_in, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{0_in, 20_in, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{0_in, 15_in, 0_deg}}, "D");

  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{24_in, -40_in, -80_deg}},
  //     "Curve To Cap");
}

void executeRedFarAuton() {
  lift.moveAbsolute(100, 100);  // Assumes 100 is the value where the extended
                                // intake can prod the cap over
  intake.moveAbsolute(50, 100); // lets say 50 is the flat floor value

  chassisController.turnAngle(-90_deg);
  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("B", true);
  profileController.waitUntilSettled();

  // profileController.turnAngle("Turn 63", 1); // right turn 63 degs
  chassisController.turnAngle(63_deg);

  lift.moveAbsolute(-100, 100); // Assumes 100 is the lift value
                                // where the intake touches ground

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  intake.moveAbsolute(30, 100); // Lets say 30 is the intake upflip value
  pros::delay(200);
  intake.moveAbsolute(50, 50); // Return to flat value

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  // profileController.turnAngle("Turn 153", -1); // left turn 153 degs
  chassisController.turnAngle(-153_deg);

  lift.moveAbsolute(100, 100); // Brings lift up to clear park platform

  chassisController.moveDistance(40_in); // park
}

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

  profileController.setTarget("Back Hit Flag", true);
  profileController.waitUntilSettled();

  profileController.setTarget("Return From Flag Hit");
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // profileController.setTarget("Closer To Cap");
  // profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.setTarget("Back From Cap", true);
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.setTarget("Back From Cap", true);
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

  profileController.setTarget("Back From Cap", true);
  lift.moveAbsolute(125, 75);
  pros::delay(500);
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  profileController.setTarget("Back From Cap", true);
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  intake.moveAbsolute(420, 200);
}

//
//

void initRedFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{5_in, 0_ft, 0_deg}}, "Back");
}

void executeRedFarParkAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(-20, 100);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.setTarget("Back", true);
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

void initBlueFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back");

  // profileController.turnPath(90_deg, "Turn 90");
}

void executeBlueFarParkAuton() {

  intake.moveAbsolute(-225, 100);
  lift.moveAbsolute(-50, 100);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  // profileController.turnAngle("Turn 90", 1);
  chassisController.turnAngle(90_deg);

  profileController.setTarget("Back", true);
  profileController.waitUntilSettled();

  chassisController.moveDistance(35_in);
}
