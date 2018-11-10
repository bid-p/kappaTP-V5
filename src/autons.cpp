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

  genTurnPath(90_deg);
  genTurnPath(63_deg);
  genTurnPath(153_deg);
}

void executeRedFarAuton() {
  lift.moveAbsolute(100, 100);  // Assumes 100 is the value where the extended
                                // intake can prod the cap over
  intake.moveAbsolute(50, 100); // lets say 50 is the flat floor value

  profileController.turnLeft();
  profileController.setTarget("Turn 90.0");
  profileController.waitUntilSettled();

  profileController.linearForward();
  profileController.setTarget("A");
  profileController.waitUntilSettled();

  profileController.linearReverse();
  profileController.setTarget("B");
  profileController.waitUntilSettled();

  profileController.turnRight();
  profileController.setTarget("Turn 63.0");
  profileController.waitUntilSettled();
  // chassisController.turnAngle(63_deg);

  lift.moveAbsolute(-100, 100); // Assumes 100 is the lift value
                                // where the intake touches ground

  profileController.linearForward();
  profileController.setTarget("C");
  profileController.waitUntilSettled();

  intake.moveAbsolute(30, 100); // Lets say 30 is the intake upflip value
  pros::delay(200);
  intake.moveAbsolute(50, 50); // Return to flat value

  profileController.linearReverse();
  profileController.setTarget("D");
  profileController.waitUntilSettled();

  profileController.turnLeft();
  profileController.setTarget("Turn 153.0");
  lift.moveAbsolute(100, 100); // Brings lift up to clear park platform
                               // as robot turns
  profileController.waitUntilSettled();
  // chassisController.turnAngle(-153_deg);

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

//
//

void initRedFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{34_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back");

  // genTurnPath(90_deg);
}

void executeRedFarParkAuton() {

  intake.moveAbsolute(-200, 100);
  lift.moveAbsolute(50, 75);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  pros::delay(500);
  profileController.waitUntilSettled();

  // profileController.turnLeft();
  // profileController.setTarget("Turn 90.0");
  // profileController.waitUntilSettled();
  chassisController.turnAngle(-90_deg);

  // profileController.linearReverse();
  // profileController.setTarget("Back");
  // profileController.waitUntilSettled();

  chassisController.moveDistance(35_in);
}

//
//

void initBlueFarParkAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{34_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back");

  // genTurnPath(90_deg);
}

void executeBlueFarParkAuton() {

  intake.moveAbsolute(-200, 100);
  lift.moveAbsolute(50, 75);

  profileController.setTarget("A");
  profileController.waitUntilSettled();

  pros::delay(500);
  profileController.waitUntilSettled();

  // profileController.turnRight();
  // profileController.setTarget("Turn 90.0");
  // profileController.waitUntilSettled();
  chassisController.turnAngle(90_deg);

  profileController.linearReverse();
  profileController.setTarget("Back");
  profileController.waitUntilSettled();

  chassisController.moveDistance(35_in);
}
