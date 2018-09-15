#include "main.h"
#include "ports.hpp"
#include "init.hpp"

#ifndef LIFT_DEFINE_GUARD
#define LIFT_DEFINE_GUARD

extern pros::Motor *lift1;

void initLiftMotors();
void setLift();
void checkLiftState();
void updateLift();

#endif
