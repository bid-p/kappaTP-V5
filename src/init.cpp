#include "main.h"

double liftTarget;
double driveTarget;
int driveDeadThresh = 10;

float theta;
float prevTheta;
float angularVelocity;

unsigned int timeNow;

tLiftStates currLiftState;

tDriveStates currDriveState;

tIntakeStates currIntakeState;

controllerIndices currRT[]{};
controllerIndices lastRT[]{};

void populateControlArrays() {

  for (int i = 0; i < 16; i++) {
    lastRT[i] = currRT[i];
  }

  // updating currRT[] values

  currRT[leftX] = controller[ControllerAnalog::leftX];
  currRT[leftY] = controller[ControllerAnalog::leftY];
  currRT[rightX] = controller[ControllerAnalog::rightX];
  currRT[rightY] = controller[ControllerAnalog::rightY];

  currRT[L1] = controller[ControllerDigital::L1];
  currRT[L2] = controller[ControllerDigital::L2];
  currRT[R1] = controller[ControllerDigital::R1];
  currRT[R2] = controller[ControllerDigital::R2];
  currRT[Up] = controller[ControllerDigital::up];
  currRT[Down] = controller[ControllerDigital::down];
  currRT[Left] = controller[ControllerDigital::left];
  currRT[Right] = controller[ControllerDigital::right];
  currRT[X] = controller[ControllerDigital::X];
  currRT[B] = controller[ControllerDigital::B];
  currRT[Y] = controller[ControllerDigital::Y];
  currRT[A] = controller[ControllerDigital::A];
}

bool btnRising(controllerIndices button) {

  if (currRT[button] && !lastRT[button]) {
    return true;
  } else {
    return false;
  }
}

bool btnFalling(controllerIndices button) {

  if (!currRT[button] && lastRT[button]) {
    return true;
  } else {
    return false;
  }
}

bool joystickRising(controllerIndices stickChannel) {

  if (currRT[stickChannel] >= driveDeadThresh &&
      lastRT[stickChannel] < driveDeadThresh) {
    return true;
  } else {
    return false;
  }
}

bool joystickFalling(controllerIndices stickChannel) {

  if (currRT[stickChannel] < driveDeadThresh &&
      lastRT[stickChannel] >= driveDeadThresh) {
    return true;
  } else {
    return false;
  }
}
