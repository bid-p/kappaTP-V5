#include "main.h"

Motor lift(MPORT_LIFT, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController liftController =
    AsyncControllerFactory::posIntegrated(MPORT_LIFT);

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

pros::Mutex liftMutex;

void updateLift() {
  liftPosition = lift.getPosition();

  if (liftRisingBtn.isPressed()) {
    currLiftState = liftRising;
    liftState = 'r';
  }
  if (liftFallingBtn.isPressed()) {
    currLiftState = liftFalling;
    liftState = 'f';
  }
  if (liftHighPoleBtn.changedToPressed()) {
    currLiftState = liftHighPole;
    liftState = 't';
  }
  if (liftLowPoleBtn.changedToPressed()) {
    currLiftState = liftLowPole;
    liftState = 'l';
  }
  if (liftFloorBtn.changedToPressed()) {
    currLiftState = liftFloor;
    liftState = 'f';
  }
}

void liftAct(void *) {
  while (true) {
    switch (currLiftState) {
    case liftNotRunning:
      lift.setBrakeMode(AbstractMotor::brakeMode::coast);
      lift.moveVoltage(0);
      break;

    case liftHolding:
      lift.moveAbsolute(liftPosition, 100);
      currLiftState = liftHolding;
      break;

    case liftRising:
      lift.moveVoltage(12000);
      currLiftState = liftHolding;
      break;

    case liftFalling:
      lift.moveVoltage(-12000);
      currLiftState = liftHolding;
      break;

    case liftLowPole:
      lift.moveAbsolute(lowPoleVal, 100);
      currLiftState = liftHolding;
      break;

    case liftHighPole:
      lift.moveAbsolute(highPoleVal, 100);
      currLiftState = liftHolding;
      break;

    case liftFloor:
      lift.moveAbsolute(floorVal, 100);
      currLiftState = liftHolding;
      break;
    }
    pros::delay(10);
  }
}
