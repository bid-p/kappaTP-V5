#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'I';

double intakePosition;

ControllerButton intakeCloseBtn = ControllerDigital::L2;
ControllerButton intakeOpenBtn = controller[ControllerDigital::L1];
ControllerButton intakeFlipMacroBtn = controller[ControllerDigital::Y];

pros::Mutex intakeMutex;

void updateIntake() {
  // intakeMutex.take(10);

  intakePosition = intake.getPosition();

  if (intakeCloseBtn.isPressed()) {
    currIntakeState = intakeClosing;
    intakeState = 'c';
  }
  if (intakeOpenBtn.isPressed()) {
    currIntakeState = intakeOpen;
    intakeState = 'o';
  }
  if (intakeFlipMacroBtn.isPressed()) {
    currIntakeState = intakeFlipMacro;
    intakeState = 'o';
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
      currIntakeState = intakeHolding;
      break;

    case intakeClosing:
      intake.moveVoltage(12000);
      currIntakeState = intakeHolding;
      break;

    case intakeOpen:
      intake.moveVoltage(-12000);
      currIntakeState = intakeHolding;
      break;

    case intakeFlipMacro:
      intake.moveAbsolute(50, 100);
      pros::delay(0);
      intake.moveAbsolute(0, 50);
      currIntakeState = intakeHolding;
      break;

      // intakeMutex.give();
      pros::delay(10);
    }
  }
}
