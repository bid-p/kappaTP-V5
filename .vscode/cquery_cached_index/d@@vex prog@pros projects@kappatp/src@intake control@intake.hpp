#include "main.h"
#include "ports.hpp"
#include "init.hpp"

#ifndef INTAKE_DEFINE_GUARD
#define INTAKE_DEFINE_GUARD

extern pros::Motor *intake;

void initMotors();
void setIntake();
void setIntakePosition();
void checkIntakeState();
void updateIntake();

#endif
