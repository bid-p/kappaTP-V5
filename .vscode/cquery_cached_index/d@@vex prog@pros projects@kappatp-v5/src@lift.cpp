#include "main.h"

Motor lift(MPORT_LIFT, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController liftController =
    AsyncControllerFactory::posIntegrated(MPORT_LIFT);

tLiftStates currLiftState;
char liftState = 'x';

double liftPosition;

ControllerButton liftUpBtn = controller[ControllerDigital::R1];
ControllerButton liftDownBtn = controller[ControllerDigital::R2];
ControllerButton liftLowPoleBtn = controller[ControllerDigital::left];
ControllerButton liftHighPoleBtn = controller[ControllerDigital::right];
ControllerButton liftFlipBtn = controller[ControllerDigital::down];
ControllerButton liftGrabBtn = controller[ControllerDigital::up];

void updateLift() {
  lift.setBrakeMode(AbstractMotor::brakeMode::hold);

  if (liftUpBtn.isPressed()) {
    currLiftState = liftRising;
    liftState = 'r';
  }
  if (liftDownBtn.isPressed()) {
    currLiftState = liftFalling;
    liftState = 'f';
  }
  if (liftUpBtn.changedToReleased()) {
    liftPosition = lift.getPosition();
    currLiftState = liftHolding;
    liftState = 'h';
  }
  if (liftDownBtn.changedToReleased()) {
    liftPosition = lift.getPosition();
    currLiftState = liftHolding;
    liftState = 'h';
  }
  if (liftHighPoleBtn.changedToPressed()) {
    currLiftState = liftHighPole;
    liftState = 't';
  }
  if (liftLowPoleBtn.changedToPressed()) {
    currLiftState = liftLowPole;
    liftState = 'l';
  }
  if (liftFlipBtn.changedToPressed()) {
    currLiftState = liftFlip;
    liftState = 'f';
  }
  if (liftGrabBtn.changedToPressed()) {
    currLiftState = liftGrab;
    liftState = 'g';
  }
}

void liftAct() {
  switch (currLiftState) {
  case liftNotRunning:
    break;

  case liftHolding:
    lift.moveAbsolute(liftPosition, 200);
    break;

  case liftRising:
    lift.moveVoltage(12000);
    break;

  case liftFalling:
    lift.moveVoltage(-12000);
    break;

  case liftLowPole:
    lift.moveAbsolute(50, 200);
    break;

  case liftHighPole:
    lift.moveAbsolute(50, 200);
    break;

  case liftFlip:
    lift.moveAbsolute(50, 200);
    break;

  case liftGrab:
    lift.moveAbsolute(50, 200);
    break;
  }
}
