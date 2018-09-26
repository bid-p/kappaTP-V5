#include "main.h"

Motor lift(MPORT_LIFT, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController liftController =
    AsyncControllerFactory::posIntegrated(MPORT_LIFT);

tLiftStates currLiftState;

ControllerButton liftUpBtn = ControllerDigital::R1;
ControllerButton liftDownBtn = ControllerDigital::R2;
ControllerButton liftLowPoleBtn = ControllerDigital::left;
ControllerButton liftHighPoleBtn = ControllerDigital::right;
ControllerButton liftFlipBtn = ControllerDigital::down;
ControllerButton liftGrabBtn = ControllerDigital::up;

void updateLift() {
  if (liftUpBtn.isPressed()) {
    currLiftState = liftRising;
  } else if (liftDownBtn.isPressed()) {
    currLiftState = liftFalling;
  }
  if (liftUpBtn.changedToReleased()) {
    currLiftState = liftHolding;
  }
  if (liftDownBtn.changedToReleased()) {
    currLiftState = liftHolding;
  }
  if (liftHighPoleBtn.changedToPressed()) {
    currLiftState = liftHighPole;
  } else if (liftLowPoleBtn.changedToPressed()) {
    currLiftState = liftLowPole;
  } else if (liftFlipBtn.changedToPressed()) {
    currLiftState = liftFlip;
  } else if (liftGrabBtn.changedToPressed()) {
    currLiftState = liftGrab;
  }
}

void liftAct() {
  switch (currLiftState) {
  case liftNotRunning:
    break;

  case liftHolding:
    break;

  case liftRising:
    lift.moveVoltage(127);
    break;

  case liftFalling:
    lift.moveVoltage(-127);
    break;

  case liftLowPole:
    liftController.setTarget(50);
    break;

  case liftHighPole:
    liftController.setTarget(50);
    break;

  case liftFlip:
    liftController.setTarget(50);
    break;

  case liftGrab:
    liftController.setTarget(50);
    break;
  }
}
