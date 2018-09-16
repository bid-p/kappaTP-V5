#ifndef INIT_DEFINE_GUARD
#define INIT_DEFINE_GUARD

#include "api.h"

using namespace pros;

extern double liftTarget;
extern double driveTarget;
extern int driveDeadThresh;

extern float theta;
extern float prevTheta;
extern float angularVelocity;

extern unsigned int timeNow;

//struct PID drivePID;

typedef enum liftStates {
    liftNotRunning,
    liftRising,
    liftFalling,
    liftHolding,
		liftPickupGround,
    liftPickupFlip,
    liftHighGoal,
    liftLowGoal,
} tLiftStates;

extern tLiftStates currLiftState;

typedef enum driveStates {
    driveNotRunning,
		driveRunning,
    driveHolding,
    //drivePoleMacro,
} tDriveStates;

extern tDriveStates currDriveState;

typedef enum intakeStates {
    intakeNotRunning,
    intakeOpen,
		intakeClose,
} tIntakeStates;

extern tIntakeStates currIntakeState;

extern int currJoyRT[4];

extern int lastJoyRT[4];

extern int currBtnRT[12];

extern int lastBtnRT[12];

extern pros::Controller *master;

extern void initController();

extern void populateControlArrays();

extern bool btnRising(controller_digital_e_t button);

extern bool btnFalling(controller_digital_e_t button);

extern bool joystickRising(controller_analog_e_t stickChannel);

extern bool joystickFalling(controller_analog_e_t stickChannel);

#endif
