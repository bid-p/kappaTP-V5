#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;

ControllerButton intakeToggleBtn = ControllerDigital::L1;
ControllerButton intakeCompleteOpenBtn = ControllerDigital::L2;

void updateIntake() {
  if (intakeToggleBtn.changedToPressed()) {
    switch(currIntakeState) {
      case intakeClosing:
        currIntakeState = intakeHalfOpen;
        break;
      case intakeFullOpen:
      case intakeHalfOpen:
        currIntakeState = intakeClosing;
        break;
      case intakeNotRunning:
        currIntakeState = intakeHalfOpen;
        break;
    }
  }
  if(intakeCompleteOpenBtn.changedToPressed()) {
    currIntakeState = intakeFullOpen;
  }
}

void intakeAct() {
  switch (currIntakeState) {
  case intakeNotRunning:
    break;

  case intakeClosing:
    intake.moveVoltage(12000);
    break;

  case intakeHalfOpen:
    intakeController.setTarget(150);
    break;
  case intakeFullOpen:
    intakeController.setTarget(400);
    break;
  }
}
