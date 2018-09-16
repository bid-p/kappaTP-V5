#ifndef LIFT_DEFINE_GUARD
#define LIFT_DEFINE_GUARD

#include "api.h"

extern pros::Motor *lift1;

void initLiftMotors();
void setLift();
void checkLiftState();
void updateLift();

#endif
