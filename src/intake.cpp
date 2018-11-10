#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'I';

double intakePosition;

ControllerButton intakeUpBtn = ControllerDigital::L2;
ControllerButton intakeDownBtn = controller[ControllerDigital::L1];
ControllerButton intakeFlipMacroBtn = controller[ControllerDigital::Y];

pros::Mutex intakeMutex;

void updateIntake() {
  // intakeMutex.take(10);

  intakePosition = intake.getPosition();

  if (intakeUpBtn.isPressed()) {
    currIntakeState = intakeUp;
    intakeState = 'u';
  }
  if (intakeDownBtn.isPressed()) {
    currIntakeState = intakeDown;
    intakeState = 'd';
  }
  if (intakeFlipMacroBtn.isPressed()) {
    currIntakeState = intakeFlipUp;
    intakeState = 'f';
  }

  // intakeMutex.give();
}

void intakeAct(void *) {
  while (true) {
    // intakeMutex.take(500);

    switch (currIntakeState) {
    case intakeNotRunning:
      intake.setBrakeMode(AbstractMotor::brakeMode::coast);
      intake.moveVoltage(0);
      break;

    case intakeHolding:
      intake.moveAbsolute(intakePosition, 100);
      break;

    case intakeUp:
      intake.moveVoltage(12000);
      currIntakeState = intakeHolding;
      break;

    case intakeDown:
      intake.moveVoltage(-5000);
      currIntakeState = intakeHolding;
      break;

    case intakeFlipUp:
      if (abs(intakePosition - 50) > 5) { // 5 is a temporary error tolerance
        intake.moveAbsolute(50, 200);
      } else {
        currIntakeState = intakeFlipDown;
      }
      break;
    case intakeFlipDown:
      if (abs(intakePosition) > 5) {
        intake.moveAbsolute(0, 100);
      } else {
        currIntakeState = intakeHolding;
        intakeState = 'f';
      }
      // intakeMutex.give();
    }
    pros::delay(10);
  }
}
