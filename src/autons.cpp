#include "main.h"

void initLeftCloseAuton() {
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

void executeLeftCloseAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  profileController.reverse();
  profileController.setTarget("Back Hit Flag");
  profileController.waitUntilSettled();

  profileController.setTarget("Return From Flag Hit");
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90._deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // profileController.setTarget("Closer To Cap");
  // profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  profileController.reverse();
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

void initLeftFarAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{2_in, 0_ft, 0_deg}}, "Center");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back From Cap");
}

void executeLeftFarAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  // profileController.setTarget("Center");
  // profileController.waitUntilSettled();
  //
  // chassisController.turnAngle(-95._deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.reverse();
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
void initRightCloseAuton() {
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

void executeRightCloseAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  profileController.reverse();
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

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.reverse();
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

void initRightFarAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{2_in, 0_ft, 0_deg}}, "Center");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{6_in, 0_ft, 0_deg}}, "Back From Cap");
}

void executeRightFarAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(-100, 75);

  // profileController.setTarget("Center");
  // profileController.waitUntilSettled();
  //
  // chassisController.turnAngle(95._deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // intake.moveAbsolute(555, 200);

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  lift.moveAbsolute(125, 75);
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.moveDistance(50_in);

  intake.moveAbsolute(420, 200);
}
