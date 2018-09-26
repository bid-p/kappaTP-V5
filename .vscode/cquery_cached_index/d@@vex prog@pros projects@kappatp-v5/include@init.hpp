#ifndef INIT_GUARD
#define INIT_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern Controller controller;

extern ControllerButton abortBtn;

extern const double joyDeadband;

extern void checkAbortSubsystems();

#endif
