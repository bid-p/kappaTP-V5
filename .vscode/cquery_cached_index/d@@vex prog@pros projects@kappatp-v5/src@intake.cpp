#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(intake);

tIntakeStates currIntakeState;
char intakeState = 'I';
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
      intakeController.flipDisable(true);
      intake.setBrakeMode(AbstractMotor::brakeMode::coast);
      intake.moveVoltage(0);
      break;

    case intakeHolding:
      intakeController.setTarget(intakePosition);
      intakeController.flipDisable(false);
      break;

    case intakeUp:
      intakeController.flipDisable(true);
      intake.moveVoltage(12000);
      currIntakeState = intakeNotRunning;
      // intakePosition = intake.getPosition();
      break;

    case intakeDown:
      intakeController.flipDisable(true);
      intake.moveVoltage(-5000);
      currIntakeState = intakeNotRunning;
      // intakePosition = intake.getPosition();
      break;

    case intakeCapHug:
      intakeController.setTarget(-188);
      intakeController.flipDisable(false);
      break;
    }
    pros::delay(10);
  }
}
