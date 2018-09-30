#ifndef LIFT_GUARD
#define LIFT_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern Motor lift;

extern AsyncPosIntegratedController liftController;

typedef enum liftStates {
  liftNotRunning,
  liftHolding,
  liftRising,
  liftFalling,
  liftLowPole,
  liftHighPole,
  liftFlip,
  liftGrab,
} tLiftStates;

extern tLiftStates currLiftState;
extern char liftState;

extern ControllerButton liftUpBtn;
extern ControllerButton liftDownBtn;
extern ControllerButton liftLowPoleBtn;
extern ControllerButton liftHighPoleBtn;
extern ControllerButton liftFlipBtn;
extern ControllerButton liftGrabBtn;

extern void updateLift();

extern void liftAct();

#endif
