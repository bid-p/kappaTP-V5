#include "main.h"

double liftTarget;
double driveTarget;
int driveDeadThresh = 10;

float theta;
float prevTheta;
float angularVelocity;

unsigned int timeNow;

Controller controller;

std::shared_ptr<ChassisControllerIntegrated> chassis =
    ChassisControllerFactory::createPtr(
        {MPORT_DRIVE_L1, MPORT_DRIVE_L2, MPORT_DRIVE_L3},    // Left Motors
        {-MPORT_DRIVE_R1, -MPORT_DRIVE_R2, -MPORT_DRIVE_R3}, // Right Motors
        AbstractMotor::gearset::green,                       // 200 RPM
        {4_in, 12.5_in} // 4 in wheels and 12.5 in wheelbase width
    );

tLiftStates currLiftState;

tDriveStates currDriveState;

tIntakeStates currIntakeState;

float currRT[];
float lastRT[];

void populateControlArrays() {

  for (int i = 0; i < 18; i++) {
    lastRT[i] = currRT[i];
  }

  // updating currRT[] values
  currRT[leftX] = controller.getAnalog(ControllerAnalog::leftX);
  currRT[leftY] = controller.getAnalog(ControllerAnalog::leftY);
  currRT[rightX] = controller.getAnalog(ControllerAnalog::rightX);
  currRT[rightY] = controller.getAnalog(ControllerAnalog::rightY);

  currRT[L1] = controller.getDigital(ControllerDigital::L1);
  currRT[L2] = controller.getDigital(ControllerDigital::L2);
  currRT[R1] = controller.getDigital(ControllerDigital::R1);
  currRT[R2] = controller.getDigital(ControllerDigital::R2);
  currRT[Up] = controller.getDigital(ControllerDigital::up);
  currRT[Down] = controller.getDigital(ControllerDigital::down);
  currRT[Left] = controller.getDigital(ControllerDigital::left);
  currRT[Right] = controller.getDigital(ControllerDigital::right);
  currRT[X] = controller.getDigital(ControllerDigital::X);
  currRT[B] = controller.getDigital(ControllerDigital::B);
  currRT[Y] = controller.getDigital(ControllerDigital::Y);
  currRT[A] = controller.getDigital(ControllerDigital::A);
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
