#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'i';
double holdPosition;

ControllerButton intakeCloseBtn = ControllerDigital::L2;
ControllerButton intakeOpenBtn = controller[ControllerDigital::L1];

void updateIntake() {
  if (intakeCloseBtn.isPressed()) {
    currIntakeState = intakeClosing;
    intakeState = 'c';
  }
 if (intakeCloseBtn.changedToReleased()){
    currIntakeState = intakeNotRunning;
    intakeState = 'x';
    holdPosition = intake.getPosition();
  }
  if (intakeOpenBtn.changedToPressed()) {
    currIntakeState = intakeOpen;
    intakeState = 'o';
  }
}

void intakeAct() {
  switch (currIntakeState) {
  case intakeNotRunning:
    intake.moveAbsolute(holdPosition, 200);
    break;

  case intakeClosing:
    intake.moveVoltage(6700);
    break;

  case intakeOpen:
    intake.moveAbsolute(120, 200);
    break;
  }
}
