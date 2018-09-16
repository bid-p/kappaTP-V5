#ifndef INTAKE_DEFINE_GUARD
#define INTAKE_DEFINE_GUARD

#include "api.h"

extern pros::Motor *intake;

void initIntakeMotors();
void setIntake();
void setIntakePosition();
void checkIntakeState();
void updateIntake();

#endif
