#include "main.h"

Motor lift(MPORT_LIFT, false, AbstractMotor::gearset::green);

pros::ADIPotentiometer liftPOT(1);

AsyncPosIntegratedController liftController =
    AsyncControllerFactory::posIntegrated(MPORT_LIFT);

tLiftStates currLiftState;
char liftState = 'x';

double liftPosition;

const int lowPoleVal = 1800;
const int highPoleVal = 2000;
const int liftFlipVal = 580;
const int liftGrabVal = 2000;

ControllerButton liftUpBtn = controller[ControllerDigital::R1];
ControllerButton liftDownBtn = controller[ControllerDigital::R2];
ControllerButton liftLowPoleBtn = controller[ControllerDigital::left];
ControllerButton liftHighPoleBtn = controller[ControllerDigital::right];
ControllerButton liftFlipBtn = controller[ControllerDigital::down];
ControllerButton liftGrabBtn = controller[ControllerDigital::up];

void updateLift() {
  // lift.setBrakeMode(AbstractMotor::brakeMode::hold);

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
    lift.setBrakeMode(AbstractMotor::brakeMode::coast);
    lift.moveVoltage(0);
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
    if (liftPOT.get_value_calibrated() < lowPoleVal - 5) {
      lift.moveVelocity(200);
      liftState = liftLowPole;
    }
    if (liftPOT.get_value_calibrated() > lowPoleVal + 5) {
      lift.moveVelocity(-200);
      liftState = liftLowPole;
    }
    if (liftPOT.get_value_calibrated() > lowPoleVal - 5 &&
        liftPOT.get_value_calibrated() < lowPoleVal + 5) {
      liftState = liftHolding;
    }
    break;

  case liftHighPole:
    if (liftPOT.get_value_calibrated() < highPoleVal - 5) {
      lift.moveVelocity(200);
      liftState = liftHighPole;
    }
    if (liftPOT.get_value_calibrated() > highPoleVal + 5) {
      lift.moveVelocity(-200);
      liftState = liftHighPole;
    }
    if (liftPOT.get_value_calibrated() > highPoleVal - 5 &&
        liftPOT.get_value_calibrated() < highPoleVal + 5) {
      liftState = liftHolding;
    }
    break;

  case liftFlip:
    if (liftPOT.get_value_calibrated() < liftFlipVal - 5) {
      lift.moveVelocity(200);
      liftState = liftFlip;
    }
    if (liftPOT.get_value_calibrated() > liftFlipVal + 5) {
      lift.moveVelocity(-200);
      liftState = liftFlip;
    }
    if (liftPOT.get_value_calibrated() > liftFlipVal - 5 &&
        liftPOT.get_value_calibrated() < liftFlipVal + 5) {
      liftState = liftHolding;
    }
    break;

  case liftGrab:
    if (liftPOT.get_value_calibrated() < liftGrabVal - 5) {
      lift.moveVelocity(200);
      liftState = liftGrab;
    }
    if (liftPOT.get_value_calibrated() > liftGrabVal + 5) {
      lift.moveVelocity(-200);
      liftState = liftGrab;
    }
    if (liftPOT.get_value_calibrated() > liftGrabVal - 5 &&
        liftPOT.get_value_calibrated() < liftGrabVal + 5) {
      liftState = liftHolding;
    }
    break;
  }
}
