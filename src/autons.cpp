#include "main.h"

void initRedCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{44_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "C");

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

  chassisController.turnAngle(-90_deg);

  lift.moveAbsolute(-20, 100);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  intake.moveAbsolute(-80, 100);
  pros::delay(600);

  chassisController.turnAngle(-90_deg);

  chassisController.moveDistance(-36_in);
}

//
//

void initBlueCloseAuton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{44_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{5_in, 0_ft, 0_deg}}, "D");
} // hella good

void executeBlueCloseAuton() {
  intake.moveAbsolute(-270, 100);
  pros::delay(500);
  lift.moveAbsolute(0, 100);

  profileController.setTarget("A", true);
  profileController.waitUntilSettled();

  profileController.setTarget("B");
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg);

  lift.moveAbsolute(-20, 100);

  profileController.setTarget("C");
  profileController.waitUntilSettled();

  profileController.setTarget("D", true);
  profileController.waitUntilSettled();

  intake.moveAbsolute(-80, 100);
  pros::delay(600);

  chassisController.turnAngle(90_deg);

  chassisController.moveDistance(-36_in);
} // hella good

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
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A"); // First Cap

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{9_in, 0_ft, 0_deg}}, "B"); // Back From
                                                                  // First Cap
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{21_in, 0_ft, 0_deg}}, "C"); // Second Cap

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{12_in, 0_ft, 0_deg}}, "D"); // Platform
                                                                   // Aligning
}

void executeRedFar2Auton() {

  intake.moveAbsolute(-270, 100); // Brings intake down from folded position
  pros::delay(500); // Waits until intake comes down to ensure doesn't get stuck
  lift.moveAbsolute(-20, 100); // lets say 50 is the flat floor value

  profileController.setTarget("A"); // Moves to the first cap
                                    // and prods the cap over
  profileController.waitUntilSettled();

  profileController.setTarget("B", true); // Moves back to clear the
                                          // first cap before it turns
  profileController.waitUntilSettled();

  chassisController.turnAngle(63_deg); // Turns to second cap

  profileController.setTarget("C"); // Moves into the second cap
  profileController.waitUntilSettled();

  intake.moveAbsolute(-60, 100); // Brings intake up to flip cap
  pros::delay(600);
  intake.moveAbsolute(-270, 100); // Returns intake down to flat value

  profileController.setTarget("D", true); // Moves back to align with platform
  profileController.waitUntilSettled();

  chassisController.turnAngle(47_deg); // Aligns with parking platform
  intake.moveAbsolute(-225, 100);

  chassisController.moveDistance(-43_in); // CLimbs parking platform backwards
}

//
//

void initBlueFar2Auton() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A"); // First Cap

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{9_in, 0_ft, 0_deg}}, "B"); // Back From
                                                                  // First Cap
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{21_in, 0_ft, 0_deg}}, "C"); // Second Cap

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{12_in, 0_ft, 0_deg}}, "D"); // Platform
                                                                   // Aligning
}

void executeBlueFar2Auton() {

  intake.moveAbsolute(-270, 100); // Brings intake down from folded position
  pros::delay(500); // Waits until intake comes down to ensure doesn't get stuck
  lift.moveAbsolute(-20, 100); // lets say -29 is the flat floor value

  profileController.setTarget("A"); // Moves to the first cap
                                    // and prods the cap over
  profileController.waitUntilSettled();

  profileController.setTarget("B", true); // Moves back to clear the
                                          // first cap before it turns
  profileController.waitUntilSettled();

  chassisController.turnAngle(-63_deg); // Turns to second cap

  profileController.setTarget("C"); // Moves into the second cap
  profileController.waitUntilSettled();

  intake.moveAbsolute(-60, 100); // Brings intake up to flip cap
  pros::delay(600);
  intake.moveAbsolute(-270, 100); // Returns intake down to flat value

  profileController.setTarget("D", true); // Moves back to align with platform
  profileController.waitUntilSettled();

  chassisController.turnAngle(-47_deg); // Aligns with parking platform
  intake.moveAbsolute(-225, 100);

  chassisController.moveDistance(-43_in); // CLimbs parking platform backwards
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

void initProgSkills() {
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{21_in, 0_ft, 0_deg}}, "B");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{20_in, 0_ft, 0_deg}}, "C");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{12_in, 0_ft, 0_deg}}, "D");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{3_in, 0_ft, 0_deg}}, "E");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{24_in, 0_ft, 0_deg}}, "F");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{45_in, 0_ft, 0_deg}}, "G");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "H");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{48_in, 0_ft, 0_deg}}, "I");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{24_in, 0_ft, 0_deg}}, "J");

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{45_in, 0_ft, 0_deg}}, "K");
}

void executeProgSkills() {
  chassisController.setMaxVelocity(200);

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "A");

  intakeController.setTarget(-80); // move intake down to safe position
  intakeController.waitUntilSettled();
  liftController.setTarget(0); // holds lift at 0 position
  liftController.waitUntilSettled();

  profileController.setTarget("A", true); // hit low flag

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{23_in, 0_ft, 0_deg}}, "B");
  // generate B while A runs

  profileController.waitUntilSettled();
  profileController.removePath("A"); // removes path A from memory

  // hit low flag

  profileController.setTarget("B"); // perpendicular align with first cap

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{20_in, 0_ft, 0_deg}}, "C");
  // generate C while B runs

  profileController.waitUntilSettled();
  profileController.removePath("B"); // removes path B from memory

  chassisController.turnAngle(-90_deg); // turn to face first cap

  chassisController.forward(-.10); // fencealign 1
  pros::delay(500);

  intakeController.setTarget(-270); // move intake down to flat position
  intakeController.waitUntilSettled();
  liftController.setTarget(-20); // move lift down under first cap
  liftController.waitUntilSettled();

  profileController.setTarget("C"); // move into first cap

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{15_in, 0_ft, 0_deg}}, "D");
  // generate D while C is running

  profileController.waitUntilSettled();
  profileController.removePath("C"); // remove path C from memory

  intakeController.setTarget(-60); // Brings intake up to flip first cap
  intakeController.waitUntilSettled();
  intakeController.setTarget(-270); // Returns intake down to flat value
  intakeController.waitUntilSettled();
  // flipped cap 1

  profileController.setTarget("D", true); // move back to perp align

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{4_in, 0_ft, 0_deg}}, "E");
  // generate E while D is running

  profileController.waitUntilSettled();
  profileController.removePath("D"); // remove path D from memory

  chassisController.forward(-.10); // fencealign 2
  pros::delay(300);

  intakeController.setTarget(-80); // Brings intake up to not
                                   // interfere with anything after fencealign
  intakeController.waitUntilSettled();

  profileController.setTarget("E"); // move forward get off the fence

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{24_in, 0_ft, 0_deg}}, "F");
  // generate F while E runs

  profileController.waitUntilSettled();
  // no remove E

  chassisController.turnAngle(90_deg); // turn right to parallel on lane

  profileController.setTarget("F"); // move forward to perp
                                    // align with second cap
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{45_in, 0_ft, 0_deg}}, "G");
  // generate G while F is running

  profileController.waitUntilSettled();
  profileController.removePath("F");

  chassisController.turnAngle(-90_deg); // turn left to face second cap

  chassisController.forward(-.10); // fencealign 3
  pros::delay(300);

  intakeController.setTarget(-270); // bring intake down to flat position
  intakeController.waitUntilSettled();
  liftController.setTarget(160); // lift up to pushing-cap-over positions
  liftController.waitUntilSettled();

  profileController.setTarget("G"); // move forward into cap to flip it over

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{42_in, 0_ft, 0_deg}}, "H");
  // Generate H while G is running
  profileController.waitUntilSettled();
  // dont remove G

  // flipped cap 2

  profileController.setTarget("H", true); // move backward to
                                          // prep for fence align

  // no need to generate I this early
  profileController.waitUntilSettled();

  intakeController.setTarget(-80); // Brings intake up to not
                                   // interfere with anything
  intakeController.waitUntilSettled();

  chassisController.forward(-.25); // fencealign
  pros::delay(600);

  profileController.setTarget("E"); // move forward to get away from fence

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{48_in, 0_ft, 0_deg}}, "I");
  // generate I while E is running for 2nd time
  profileController.waitUntilSettled();
  // DO NOT remove E

  chassisController.turnAngle(90_deg); // turns right parallel to fence

  profileController.setTarget("I"); // moves to perp align with third cap
  profileController.waitUntilSettled();

  chassisController.turnAngle(-90_deg); // turn left to face third cap

  chassisController.forward(-.25); // fencealign
  pros::delay(600);

  intakeController.setTarget(-270); // bring intake down to flat position
  intakeController.waitUntilSettled();
  liftController.setTarget(160);
  liftController.waitUntilSettled(); // lift up to pushing-cap-over positions

  profileController.setTarget("G"); // move forward into cap to flip it over
  profileController.waitUntilSettled();

  // flipped cap 3
  profileController.setTarget("H", true); // move backward to
                                          // prep for fence align

  // no need to generate J this early
  profileController.waitUntilSettled();

  profileController.removePath("G"); // dont need G anymore
  profileController.removePath("H"); // dont need H anymore

  liftController.setTarget(0); // bring lift down
  liftController.waitUntilSettled();

  intakeController.setTarget(-80); // Brings intake up to not
                                   // interfere with anything
  intakeController.waitUntilSettled();

  chassisController.forward(-.25); // fencealign
  pros::delay(600);

  profileController.setTarget("E"); // move forward to get off fence

  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{24_in, 0_ft, 0_deg}}, "J");
  // generate J during E's third time
  profileController.waitUntilSettled();

  chassisController.turnAngle(90_deg); // turn 90 to parallel with fence

  profileController.setTarget("J"); // move forward to perp
                                    // align with fourth cap
  profileController.generatePath(
      {Point{0_ft, 0_ft, 0_deg}, Point{45_in, 0_ft, 0_deg}}, "K");
  // generate K while J is running

  profileController.waitUntilSettled();
  profileController.removePath("J");

  chassisController.turnAngle(-90_deg); // turn left to face 4th cap

  intakeController.setTarget(-270); // Returns intake down to flat value
  intakeController.waitUntilSettled();

  liftController.setTarget(-20); // bring intake down to
                                 // slide under cap position
  liftController.waitUntilSettled();

  chassisController.forward(-.25); // fencealign
  pros::delay(600);

  profileController.setTarget("K"); // move into 4th cap
  profileController.waitUntilSettled();

  intakeController.setTarget(-60); // Brings intake up to flip cap
  intakeController.waitUntilSettled();
  intakeController.setTarget(-270); // Returns intake down to flat value
  intakeController.waitUntilSettled();
}
