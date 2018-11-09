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
  intakeFlipMacro,
} tIntakeStates;

extern tIntakeStates currIntakeState;

extern char intakeState;

extern double intakePosition;

extern ControllerButton intakeCloseBtn;
extern ControllerButton intakeOpenBtn;
extern ControllerButton intakeFlipMacroBtn;

extern pros::Mutex intakeMutex;

extern void updateIntake();

extern void intakeAct(void *);

#endif
