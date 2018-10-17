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
const int flipVal = 580;
const int grabVal = 2000;

ControllerButton liftUpBtn = controller[ControllerDigital::R1];
ControllerButton liftDownBtn = controller[ControllerDigital::R2];
ControllerButton liftLowPoleBtn = controller[ControllerDigital::left];
ControllerButton liftHighPoleBtn = controller[ControllerDigital::right];
ControllerButton liftFlipBtn = controller[ControllerDigital::down];
ControllerButton liftGrabBtn = controller[ControllerDigital::up];

void liftMacro(int targetVal, int threshold, tLiftStates macroState) {
  if (liftPOT.get_value_calibrated() < targetVal - threshold) {
    lift.moveVelocity(200);
    currLiftState = macroState;
  }
  if (liftPOT.get_value_calibrated() > targetVal + threshold) {
    lift.moveVelocity(-200);
    currLiftState = macroState;
  }
  if (liftPOT.get_value_calibrated() > targetVal - threshold &&
      liftPOT.get_value_calibrated() < targetVal + threshold) {
    currLiftState = liftHolding;
  }
}

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
    lift.moveAbsolute(liftPosition, 175);
    break;

  case liftRising:
    lift.moveVoltage(12000);
    break;

  case liftFalling:
    lift.moveVoltage(-12000);
    break;

  case liftLowPole:
    liftMacro(lowPoleVal, 5, liftLowPole);
    break;

  case liftHighPole:
    liftMacro(highPoleVal, 5, liftHighPole);
    break;

  case liftFlip:
    liftMacro(flipVal, 5, liftFlip);
    break;

  case liftGrab:
    liftMacro(grabVal, 5, liftGrab);
    break;
  }
}
