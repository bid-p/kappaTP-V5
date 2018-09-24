#include "main.h"
#include "ports.hpp"
#include "init.hpp"

#ifndef INTAKE_DEFINE_GUARD
#define INTAKE_DEFINE_GUARD

extern pros::Motor *driveR1;
extern pros::Motor *driveR2;
extern pros::Motor *driveR3;
extern pros::Motor *driveL1;
extern pros::Motor *driveL2;
extern pros::Motor *driveL3;

void initDriveMotors();

#endif
