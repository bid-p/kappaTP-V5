#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;

ControllerButton intakeCloseBtn = ControllerDigital::L2;
ControllerButton intakeOpenBtn = ControllerDigital::L1;

void updateIntake() {
  if (intakeCloseBtn.changedToPressed()) {
    currIntakeState = intakeClosing;
  }
  if (intakeOpenBtn.changedToPressed()) {
    currIntakeState = intakeOpen;
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
    intakeController.setTarget(50);
    break;
  }
}
