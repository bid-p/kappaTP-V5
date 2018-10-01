#include "main.h"

Motor lift(MPORT_LIFT, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController liftController =
    AsyncControllerFactory::posIntegrated(MPORT_LIFT);

tLiftStates currLiftState;
char liftState = 'x';

ControllerButton liftUpBtn = controller[ControllerDigital::R1];
ControllerButton liftDownBtn = controller[ControllerDigital::R2];
ControllerButton liftLowPoleBtn = controller[ControllerDigital::left];
ControllerButton liftHighPoleBtn = controller[ControllerDigital::right];
ControllerButton liftFlipBtn = controller[ControllerDigital::down];
ControllerButton liftGrabBtn = controller[ControllerDigital::up];

void updateLift() {
lift.setBrakeMode(AbstractMotor::brakeMode::hold);

  currLiftState = liftHolding;
  liftState = 'h';

  if (liftUpBtn.isPressed()) {
    currLiftState = liftRising;
    liftState = 'r';
  }
  if (liftDownBtn.isPressed()) {
    currLiftState = liftFalling;
    liftState = 'f';
  }
  // if (liftHighPoleBtn.changedToPressed()) {
  //   currLiftState = liftHighPole;
  //   liftState = 't';
  // }
  // if (liftLowPoleBtn.changedToPressed()) {
  //   currLiftState = liftLowPole;
  //   liftState = 'l';
  // }
  // if (liftFlipBtn.changedToPressed()) {
  //   currLiftState = liftFlip;
  //   liftState = 'f';
  // }
  // if (liftGrabBtn.changedToPressed()) {
  //   currLiftState = liftGrab;
  //   liftState = 'g';
  // }
}

void liftAct() {
  switch (currLiftState) {
  case liftNotRunning:
    break;

  case liftHolding:
    lift.moveVelocity(0);
    break;

  case liftRising:
    lift.moveVoltage(12000);
    break;

  case liftFalling:
    lift.moveVoltage(-12000);
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
