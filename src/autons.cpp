#include "main.h"

void initLeftCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "Back Hit Flag");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}},
      "Return From Flag Hit");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{40_in, 0_ft, 0_deg}}, "Move To Cap");
  // profileController.generatePath(
  //     {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To
  //     Cap");
  //
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{4_in, 0_ft, 0_deg}}, "Back From Cap");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Reverse To
      Park");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{55_in, 0_ft, 0_deg}}, "Park");
}

void executeLeftCloseAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(0, 75);

  profileController.reverse();
  profileController.setTarget("Back Hit Flag");
  profileController.waitUntilSettled();

  profileController.setTarget("Return From Flag Hit");
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);
  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  // profileController.setTarget("Closer To Cap");
  // profileController.waitUntilSettled();

  intake.moveAbsolute(555, 200);

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  // profileController.reverse();
  profileController.setTarget("Reverse To Park");
  profileController.waitUntilSettled();

  lift.moveAbsolute(100, 75);
  profileController.setTarget("Park");
  profileController.waitUntilSettled();

  intake.moveAbsolute(420, 200);
}

void initLeftFarAuton() {

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{30_in, 0_ft, 0_deg}}, "Move To Cap");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Closer To Cap");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{4_in, 0_ft, 0_deg}}, "Back From Cap");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{10_in, 0_ft, 0_deg}}, "Reverse To Park");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{55_in, 0_ft, 0_deg}}, "Park");
}

void executeLeftFarAuton() {

  lift.moveAbsolute(50, 75);
  intake.moveAbsolute(420, 200);
  lift.moveAbsolute(0, 75);

  chassisController.turnAngle(-90_deg);

  profileController.setTarget("Move To Cap");
  profileController.waitUntilSettled();

  profileController.setTarget("Closer To Cap");
  profileController.waitUntilSettled();

  intake.moveAbsolute(555, 200);

  profileController.reverse();
  profileController.setTarget("Back From Cap");
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg);

  profileController.reverse();
  profileController.setTarget("Reverse To Park");
  profileController.waitUntilSettled();

  lift.moveAbsolute(100, 75);
  profileController.setTarget("Park");
  profileController.waitUntilSettled();

  intake.moveAbsolute(420, 200);
}
