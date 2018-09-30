#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'x';

// ControllerButton intakeCloseBtn = ControllerDigital::L2;
ControllerButton intakeToggleBtn = ControllerDigital::L1;

void updateIntake() {
  if (intakeToggleBtn.changedToPressed()) {
    switch (currIntakeState) {
    case intakeOpen:
      currIntakeState = intakeClosing;
      break;

    case intakeClosing:
      currIntakeState = intakeOpen;
      break;

    case intakeNotRunning:
      currIntakeState = intakeOpen;
      break;
    }
  }
}

void intakeAct() {
  switch (currIntakeState) {
  case intakeNotRunning:
    break;

  case intakeClosing:
    intake.moveVoltage(70);
    break;

  case intakeOpen:
    intakeController.setTarget(70);
    break;
  }
}
