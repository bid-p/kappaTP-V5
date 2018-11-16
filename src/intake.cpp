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

pros::Mutex intakeMutex;

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
      currLiftState = liftHolding;
      break;

    case intakeUp:
      intake.moveVoltage(12000);
      currIntakeState = intakeHolding;
      intakePosition = intake.getPosition();
      break;

    case intakeDown:
      intake.moveVoltage(-5000);
      currIntakeState = intakeHolding;
      intakePosition = intake.getPosition();
      break;

    case intakeCapHug:
      intake.moveAbsolute(-240, 100);
      currIntakeState = intakeHolding;
      intakePosition = intake.getPosition();
      break;
    }

    pros::delay(10);
  }
}
