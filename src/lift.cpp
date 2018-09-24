#include "main.h"

void setLift(int power) { lift1.moveVoltage(power); }

void checkLiftState() {
  if (btnRising(R1)) {
    currLiftState = liftRising;
  }
  if (btnFalling(R1)) {
    currLiftState = liftHolding;
  }
  if (btnRising(R2)) {
    currLiftState = liftFalling;
  }
  if (btnFalling(R2)) {
    currLiftState = liftHolding;
  }
}

void updateLift() {

  switch (currLiftState) {
  case liftNotRunning:
    break;

  case liftRising:
    setLift(127);
    break;

  case liftFalling:
    setLift(-127);
    break;

  case liftHolding:
    liftTarget = lift1.get_position();
    lift1.moveRelative(0, 200);
    break;

  case liftPickupGround:
    liftTarget = 50;
    lift1.moveAbsolute(liftTarget, 200);
    break;

  case liftPickupFlip:
    liftTarget = 50;
    lift1.moveAbsolute(liftTarget, 200);
    break;

  case liftHighGoal:
    liftTarget = 50;
    lift1.moveAbsolute(liftTarget, 200);
    break;

  case liftLowGoal:
    liftTarget = 50;
    lift1.moveAbsolute(liftTarget, 200);
    break;
  }
}
