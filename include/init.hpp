#ifndef INIT_DEFINE_GUARD
#define INIT_DEFINE_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

Controller controller;

extern double liftTarget;
extern double driveTarget;
extern int driveDeadThresh;

extern float theta;
extern float prevTheta;
extern float angularVelocity;

extern unsigned int timeNow;

// struct PID drivePID;

enum controllerIndices {
  leftX,
  leftY,
  rightX,
  rightY,
  L1,
  L2,
  R1,
  R2,
  Up,
  Down,
  Left,
  Right,
  X,
  B,
  Y,
  A
};

typedef enum liftStates {
  liftNotRunning,
  liftRising,
  liftFalling,
  liftHolding,
  liftPickupGround,
  liftPickupFlip,
  liftHighGoal,
  liftLowGoal,
} tLiftStates;

extern tLiftStates currLiftState;

typedef enum driveStates {
  driveNotRunning,
  driveRunning,
  driveHolding,
  // drivePoleMacro,
} tDriveStates;

extern tDriveStates currDriveState;

typedef enum intakeStates {
  intakeNotRunning,
  intakeOpen,
  intakeClose,
} tIntakeStates;

extern tIntakeStates currIntakeState;

extern controllerIndices currRT[16];
extern controllerIndices lastRT[16];

extern void populateControlArrays();

extern bool btnRising(controllerIndices button);

extern bool btnFalling(controllerIndices button);

extern bool joystickRising(controllerIndices stickChannel);

extern bool joystickFalling(controllerIndices stickChannel);

#endif
