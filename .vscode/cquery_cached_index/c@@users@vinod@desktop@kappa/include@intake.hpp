#ifndef INTAKE_GUARD
#define INTAKE_GUARD

#include "api.h"
#include "okapi/api.hpp"

using namespace okapi;

extern Motor intake;

extern AsyncPosIntegratedController intakeController;

typedef enum intakeStates {
  intakeNotRunning,
  intakeHolding,
  intakeClosing,
  intakeOpen,
} tIntakeStates;

extern tIntakeStates currIntakeState;

extern char intakeState;

extern double intakePosition;

extern ControllerButton intakeCloseBtn;
extern ControllerButton intakeOpenBtn;

extern void updateIntake();

extern void intakeAct();

#endif
