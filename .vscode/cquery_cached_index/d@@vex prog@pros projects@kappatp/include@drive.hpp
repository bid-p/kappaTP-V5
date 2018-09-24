#ifndef DRIVE_DEFINE_GUARD
#define DRIVE_DEFINE_GUARD

#include "api.h"
#include "okapi/api.hpp"
#include "ports.hpp"

using namespace okapi;

extern Motor *driveR1;
extern Motor *driveR2;
extern Motor *driveR3;
extern Motor *driveL1;
extern Motor *driveL2;
extern Motor *driveL3;

void changeDriveState();
void checkDriveState();
void driveTank();
void updateDrive();

#endif
