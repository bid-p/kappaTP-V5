#ifndef INTAKE_GUARD
#define INTAKE_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern Motor intake;

extern AsyncPosIntegratedController intakeController;

typedef enum intakeStates {
  intakeNotRunning,
  intakeClosing,
  intakeOpen,
} tIntakeStates;

extern tIntakeStates currIntakeState;

extern ControllerButton intakeCloseBtn;
extern ControllerButton intakeOpenBtn;

extern void updateIntake();

extern void intakeAct();

#endif
