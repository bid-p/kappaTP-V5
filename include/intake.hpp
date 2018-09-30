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
  intakeHalfOpen,
  intakeFullOpen,
} tIntakeStates;

extern tIntakeStates currIntakeState;

extern ControllerButton intakeToggleBtn;
extern ControllerButton intakeCompleteOpenBtn;

extern void updateIntake();

extern void intakeAct();

#endif
