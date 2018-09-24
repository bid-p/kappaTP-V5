#ifndef INIT_DEFINE_GUARD
#define INIT_DEFINE_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern Controller controller;

extern std::shared_ptr<ChassisControllerIntegrated> chassis;

extern double liftTarget;
extern double driveTarget;
extern int driveDeadThresh;

extern float theta;
extern float prevTheta;
extern float angularVelocity;

extern unsigned int timeNow;

// struct PID drivePID;

enum controllerIndices {
  leftX = 0,
  leftY = 1,
  rightX = 2,
  rightY = 3,
  L1 = 6,
  L2 = 7,
  R1 = 8,
  R2 = 9,
  Up = 10,
  Down = 11,
  Left = 12,
  Right = 13,
  X = 14,
  B = 15,
  Y = 16,
  A = 17
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

extern float currRT[18];
extern float lastRT[18];

extern void populateControlArrays();

extern bool btnRising(controllerIndices button);

extern bool btnFalling(controllerIndices button);

extern bool joystickRising(controllerIndices stickChannel);

extern bool joystickFalling(controllerIndices stickChannel);

#endif
