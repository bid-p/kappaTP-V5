#ifndef DRIVE_GUARD
#define DRIVE_GUARD

#include "api.h"
#include "okapi/api.hpp"
#include "ports.hpp"

using namespace okapi;

extern Motor driveR1;
extern Motor driveR2;
extern Motor driveR3;
extern Motor driveL1;
extern Motor driveL2;
extern Motor driveL3;

extern ChassisControllerIntegrated chassisController;

extern ControllerButton driveHoldBtn;

typedef enum driveStates {
  driveNotRunning,
  driveRunning,
  driveHolding,
  driveCoasting,
  driveTurnBraking,
  // drivePoleMacro,
} tDriveStates;

extern tDriveStates currDriveState;

extern void updateDrive();

extern void driveAct();

#endif
