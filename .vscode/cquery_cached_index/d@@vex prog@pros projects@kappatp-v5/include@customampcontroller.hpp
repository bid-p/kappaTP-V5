#ifndef _MANAS_CONTROLLER_HPP_
#define _MANAS_CONTROLLER_HPP_

#include "okapi/api/control/async/asyncMotionProfileController.hpp"

namespace okapi {
class CustomAMPController : public AsyncMotionProfileController {
public:
  int leftDirection = 1;
  int rightDirection = 1;

  using AsyncMotionProfileController::AsyncMotionProfileController;

  void executeSinglePath(const TrajectoryPair &path,
                         std::unique_ptr<AbstractRate> rate) override {
    currentPosition = 0;
    pathLength = path.length;
    auto linearSpeedToRotationalSpeed = [&](QSpeed linearMps) -> QAngularSpeed {
      return linearMps * (360_deg / (1_pi * 4.125_in));
    };

    for (int i = 0; i < path.length && !isDisabled(); ++i) {
      auto leftRPM = linearSpeedToRotationalSpeed(path.left[i].velocity * mps)
                         .convert(rpm) *
                     leftDirection;
      auto rightRPM = linearSpeedToRotationalSpeed(path.right[i].velocity * mps)
                          .convert(rpm) *
                      rightDirection;
      logger->info(
          std::to_string(
              leftRPM /*/ toUnderlyingType(AbstractMotor::gearset::green)*/) +
          ", " +
          std::to_string(
              rightRPM /*/ toUnderlyingType(AbstractMotor::gearset::green)*/));
      model->left(leftRPM / 200.0
                  /*toUnderlyingType(AbstractMotor::gearset::green)*/);
      model->right(rightRPM / 200.0
                   /*toUnderlyingType(AbstractMotor::gearset::green)*/);

      rate->delayUntil(1_ms);
    }
    rightDirection = 1;
    leftDirection = 1;
  }

  bool isPathComplete() { return (currentPosition >= pathLength); }

  void waitUntilPathComplete() {
    while (!isPathComplete()) {
      pros::delay(50);
    }
  }

  /**
   * Execute the next path with the robot reversing.
   * Return: 1 if running forward, -1 running backward.
   */
  int linearForward() {
    this->leftDirection = 1;
    this->rightDirection = 1;
    return 1;
  }

  int linearReverse() {
    this->leftDirection = -1;
    this->rightDirection = -1;
    return -1;
  }

  int turnRight() {
    this->leftDirection = -1;
    this->rightDirection = 1;
    return 1;
  }

  int turnLeft() {
    this->leftDirection = 1;
    this->rightDirection = -1;
    return -1;
  }

  void stop() { isRunning = false; }

private:
  int currentPosition;
  int pathLength;

  float mpsToRpm(float mps) {
    // (meters / second) * (60 sec / 1 minute) * (1 inch / 0.0254 meters) * (1
    // rotation / (diameter * pi)
    float rpm = (mps * 60.0) / (0.0254 * 4.125 * PI);
    return rpm;
  }
};
} // namespace okapi

#endif
