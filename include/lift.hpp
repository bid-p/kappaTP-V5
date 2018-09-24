#ifndef LIFT_DEFINE_GUARD
#define LIFT_DEFINE_GUARD

#include "api.h"
#include "okapi/api.hpp"
#include "ports.hpp"

using namespace okapi;

Motor lift1(MPORT_LIFT, false, AbstractMotor::gearset::green,
            AbstractMotor::encoderUnits::degrees);

void setLift();
void checkLiftState();
void updateLift();

#endif
