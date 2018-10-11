#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::green);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'i';

double intakePosition;

ControllerButton intakeCloseBtn = ControllerDigital::L2;
ControllerButton intakeOpenBtn = controller[ControllerDigital::L1];

void updateIntake() {
  if (intakeCloseBtn.isPressed()) {
    currIntakeState = intakeClosing;
    intakeState = 'c';
  }
  if (intakeCloseBtn.changedToReleased()) {
    currIntakeState = intakeHolding;
    intakePosition = intake.getPosition();
    intakeState = 'x';
  }
  if (intakeOpenBtn.changedToPressed()) {
    currIntakeState = intakeOpen;
    intakeState = 'o';
  }
}

void intakeAct() {
  switch (currIntakeState) {
  case intakeNotRunning:
    intake.setBrakeMode(AbstractMotor::brakeMode::coast);
    intake.moveVoltage(0);
    break;

  case intakeHolding:
    intake.moveAbsolute(intakePosition, 200);
    break;

  case intakeClosing:
    intake.moveVoltage(6700);
    break;

  case intakeOpen:
    intake.moveAbsolute(120, 200);
    break;
  }
}
