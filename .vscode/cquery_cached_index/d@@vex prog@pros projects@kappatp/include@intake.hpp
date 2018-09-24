#ifndef INTAKE_DEFINE_GUARD
#define INTAKE_DEFINE_GUARD

#include "api.h"
#include "okapi/api.hpp"
#include "ports.hpp"

using namespace okapi;

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::red,
             AbstractMotor::encoderUnits::degrees);

void initIntakeMotors();
void setIntake();
void setIntakePosition();
void checkIntakeState();
void updateIntake();

#endif
