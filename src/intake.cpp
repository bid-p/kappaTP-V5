#include "main.h"

Motor intake(MPORT_INTAKE, false, AbstractMotor::gearset::red);

AsyncPosIntegratedController intakeController =
    AsyncControllerFactory::posIntegrated(MPORT_INTAKE);

tIntakeStates currIntakeState;
char intakeState = 'I';
int upErr = 5;
int downErr = 5;
int flipUpPos = 200;
double intakePosition;

ControllerButton intakeUpBtn = ControllerDigital::L2;
ControllerButton intakeDownBtn = controller[ControllerDigital::L1];
ControllerButton intakeFlipMacroBtn = controller[ControllerDigital::Y];

pros::Mutex intakeMutex;

int counter = 0;

void updateIntake() {
  // intakeMutex.take(10);

  intakePosition = intake.getPosition();
  // if(currIntakeState != intakeFlipUp && currIntakeState != intakeFlipDown) {
  //   currIntakeState = intakeNotRunning;
  //   intakeState = 'h';
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
  // } else {
  //   if(abs(intakePosition - flipUpPos) < upErr && currIntakeState == intakeFlipUp) {
  //     currIntakeState = intakeFlipDown;
  //     intakeState = 'l';
  //   }
  //   if(abs(intakePosition) < downErr && currIntakeState == intakeFlipDown) {
  //     currIntakeState = intakeHolding;
  //     intakeState = 'h';
  //   }
  // }
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
      intake.moveRelative(0, 100);
      break;

    case intakeUp:
      intake.moveVoltage(12000);
      currIntakeState = intakeHolding;
      break;

    case intakeDown:
      intake.moveVoltage(-5000);
      currIntakeState = intakeHolding;
      break;

    // case intakeFlipUp:
    //   intake.moveAbsolute(flipUpPos, 200);
    //   break;
    // case intakeFlipDown:
    //   intake.moveAbsolute(0, 35);
    //   break;
      // intakeMutex.give();
    }
    pros::delay(10);
  }
}
