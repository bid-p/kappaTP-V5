#include "main.h"

using namespace pros;

void setIntake(int power) { intake.moveVoltage(power); }

void setIntakePosition(int position) { intake.moveAbsolute(position, 100); }

void checkIntakeState() {
  if (btnRising(L1)) {
    currIntakeState = intakeOpen;
  }
  if (btnRising(L2)) {
    currIntakeState = intakeClose;
  }
}

void updateIntake() {

  switch (currIntakeState) {
  case intakeNotRunning:
    break;

  case intakeOpen:
    setIntakePosition(50);
    break;

  case intakeClose:
    setIntake(127);
    break;
  }
}
