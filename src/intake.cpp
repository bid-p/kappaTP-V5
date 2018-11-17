#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'I';
int flipUpPos = 200;
double intakePosition;

ControllerButton intakeUpBtn = ControllerDigital::L2;
ControllerButton intakeDownBtn = controller[ControllerDigital::L1];
ControllerButton intakeCapHugBtn = controller[ControllerDigital::Y];

void updateIntake() {
  if (intakeUpBtn.isPressed()) {
    currIntakeState = intakeUp;
    intakeState = 'u';
  }
  if (intakeDownBtn.isPressed()) {
    currIntakeState = intakeDown;
    intakeState = 'd';
  }
  if (intakeCapHugBtn.isPressed()) {
    currIntakeState = intakeCapHug;
    intakeState = 'h';
  }
}

void intakeAct(void *) {
  while (true) {
    switch (currIntakeState) {
    case intakeNotRunning:
      intake.setBrakeMode(AbstractMotor::brakeMode::coast);
      intake.moveVoltage(0);
      break;

    case intakeHolding:
      intake.moveAbsolute(intakePosition, 100);
      currIntakeState = intakeNotRunning;
      break;

    case intakeUp:
      intake.moveVoltage(12000);
      currIntakeState = intakeNotRunning;
      // intakePosition = intake.getPosition();
      break;

    case intakeDown:
      intake.moveVoltage(-5000);
      currIntakeState = intakeNotRunning;
      // intakePosition = intake.getPosition();
      break;

    case intakeCapHug:
      intake.moveAbsolute(-188, 100);
      break;

    case intakeLockdown:
      intakeState = 'L';
      intake.moveAbsolute(-60, 100);
      intakePosition = intake.getPosition();
      currIntakeState = intakeHolding;
      break;
    }

    pros::delay(10);
  }
}
