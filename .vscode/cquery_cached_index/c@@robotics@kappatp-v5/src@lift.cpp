#include "main.h"

Motor lift(MPORT_LIFT, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController liftController =
    AsyncControllerFactory::posIntegrated(lift);

tLiftStates currLiftState;
char liftState = 'L';

double liftPosition;

const int lowPoleVal = 543;
const int highPoleVal = 1150;
const int floorVal = -20;

ControllerButton liftRisingBtn = controller[ControllerDigital::R1];
ControllerButton liftFallingBtn = controller[ControllerDigital::R2];
ControllerButton liftLowPoleBtn = controller[ControllerDigital::left];
ControllerButton liftHighPoleBtn = controller[ControllerDigital::right];
ControllerButton liftFloorBtn = controller[ControllerDigital::down];

void updateLift() {
  liftPosition = lift.getPosition(); // records lift position every loop

  if (liftRisingBtn.isPressed()) { // sets state to rising if
                                   // rising button pressed
    currLiftState = liftRising;
    liftState = 'r';
  }
  if (liftFallingBtn.isPressed()) { // sets state to rising if
                                    // falling button pressed
    currLiftState = liftFalling;
    liftState = 'f';
  }
  if (liftHighPoleBtn.changedToPressed()) { // sets state to high macro if right
                                            // button pressed
    currLiftState = liftHighPole;
    liftState = 't';
  }
  if (liftLowPoleBtn.changedToPressed()) { // sets state to low macro if
                                           // left pressed
    currLiftState = liftLowPole;
    liftState = 'l';
  }
  if (liftFloorBtn.changedToPressed()) { // //sets state to floor if
                                         // down button pressed
    currLiftState = liftFloor;
    liftState = 'f';
  }
}

void liftAct(void *) {
  while (true) {
    switch (currLiftState) {
    case liftNotRunning:
      liftController.flipDisable(true);
      lift.setBrakeMode(AbstractMotor::brakeMode::coast); // coasts the lift and
                                                          // sets it to 0 power
      lift.moveVoltage(0);
      break;

    case liftHolding:
      liftController.setTarget(liftPosition); // sets the lift height to
                                              // the saved liftPosition value
      liftController.flipDisable(false);
      break;

    case liftRising:
      liftController.flipDisable(true);
      lift.moveVoltage(12000);     // raises the lift at 12000mV
      currLiftState = liftHolding; // sets the default state to liftHolding
      break;

    case liftFalling:
      liftController.flipDisable(true);
      lift.moveVoltage(-12000);    // lowers the lift at 12000mV
      currLiftState = liftHolding; // sets the default state to liftHolding
      break;

    case liftLowPole:
      liftController.setTarget(lowPoleVal); // moves the lift to low pole height
      liftController.flipDisable(false);
      break;

    case liftHighPole:
      liftController.setTarget(highPoleVal); // moves lift to high pole height
      liftController.flipDisable(false);
      break;

    case liftFloor:
      liftController.setTarget(floorVal); // moves lift to floor value
      liftController.flipDisable(false);
      break;
    }
    pros::delay(10);
  }
}
