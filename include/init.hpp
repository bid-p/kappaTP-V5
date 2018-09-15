#include "main.h"

using namespace pros;

#ifndef INIT_DEFINE_GUARD
#define INIT_DEFINE_GUARD

pros::Controller master(pros::E_CONTROLLER_MASTER);

int currJoyRT[]{
  E_CONTROLLER_ANALOG_LEFT_X,
  E_CONTROLLER_ANALOG_LEFT_Y,
  E_CONTROLLER_ANALOG_RIGHT_X,
  E_CONTROLLER_ANALOG_RIGHT_Y
};

int lastJoyRT[]{
  E_CONTROLLER_ANALOG_LEFT_X,
  E_CONTROLLER_ANALOG_LEFT_Y,
  E_CONTROLLER_ANALOG_RIGHT_X,
  E_CONTROLLER_ANALOG_RIGHT_Y
};

int currBtnRT[]{
  E_CONTROLLER_DIGITAL_L1,
  E_CONTROLLER_DIGITAL_L2,
  E_CONTROLLER_DIGITAL_R1,
  E_CONTROLLER_DIGITAL_R2,
  E_CONTROLLER_DIGITAL_UP,
  E_CONTROLLER_DIGITAL_DOWN,
  E_CONTROLLER_DIGITAL_LEFT,
  E_CONTROLLER_DIGITAL_RIGHT,
  E_CONTROLLER_DIGITAL_X,
  E_CONTROLLER_DIGITAL_B,
  E_CONTROLLER_DIGITAL_Y,
  E_CONTROLLER_DIGITAL_A
};

int lastBtnRT[]{
  E_CONTROLLER_DIGITAL_L1,
  E_CONTROLLER_DIGITAL_L2,
  E_CONTROLLER_DIGITAL_R1,
  E_CONTROLLER_DIGITAL_R2,
  E_CONTROLLER_DIGITAL_UP,
  E_CONTROLLER_DIGITAL_DOWN,
  E_CONTROLLER_DIGITAL_LEFT,
  E_CONTROLLER_DIGITAL_RIGHT,
  E_CONTROLLER_DIGITAL_X,
  E_CONTROLLER_DIGITAL_B,
  E_CONTROLLER_DIGITAL_Y,
  E_CONTROLLER_DIGITAL_A
};

double liftTarget;
double driveTarget;
int driveDeadThresh = 10;

float theta;
float prevTheta;
float angularVelocity;

unsigned int timeNow;

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

tLiftStates currLiftState;

typedef enum driveStates {
    driveNotRunning,
		driveRunning,
    driveHolding,
    //drivePoleMacro,
} tDriveStates;

tDriveStates currDriveState;

typedef enum intakeStates {
    intakeNotRunning,
    intakeOpen,
		intakeClose,
} tIntakeStates;

tIntakeStates currIntakeState;

void populateControlArrays(){

	//updating lastRT[] values

	lastJoyRT[E_CONTROLLER_ANALOG_LEFT_X] = currJoyRT[E_CONTROLLER_ANALOG_LEFT_X];
	lastJoyRT[E_CONTROLLER_ANALOG_LEFT_Y] = currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y];
	lastJoyRT[E_CONTROLLER_ANALOG_RIGHT_X] = currJoyRT[E_CONTROLLER_ANALOG_RIGHT_X];
	lastJoyRT[E_CONTROLLER_ANALOG_RIGHT_Y] = currJoyRT[E_CONTROLLER_ANALOG_RIGHT_Y];

	lastBtnRT[E_CONTROLLER_DIGITAL_L1] = currBtnRT[E_CONTROLLER_DIGITAL_L1];
	lastBtnRT[E_CONTROLLER_DIGITAL_L2] = currBtnRT[E_CONTROLLER_DIGITAL_L2];
	lastBtnRT[E_CONTROLLER_DIGITAL_R1] = currBtnRT[E_CONTROLLER_DIGITAL_R1];
	lastBtnRT[E_CONTROLLER_DIGITAL_R2] = currBtnRT[E_CONTROLLER_DIGITAL_R2];
	lastBtnRT[E_CONTROLLER_DIGITAL_UP] = currBtnRT[E_CONTROLLER_DIGITAL_UP];
	lastBtnRT[E_CONTROLLER_DIGITAL_DOWN] = currBtnRT[E_CONTROLLER_DIGITAL_DOWN];
	lastBtnRT[E_CONTROLLER_DIGITAL_LEFT] = currBtnRT[E_CONTROLLER_DIGITAL_LEFT];
	lastBtnRT[E_CONTROLLER_DIGITAL_RIGHT] = currBtnRT[E_CONTROLLER_DIGITAL_RIGHT];
	lastBtnRT[E_CONTROLLER_DIGITAL_X] = currBtnRT[E_CONTROLLER_DIGITAL_X];
	lastBtnRT[E_CONTROLLER_DIGITAL_B] = currBtnRT[E_CONTROLLER_DIGITAL_B];
	lastBtnRT[E_CONTROLLER_DIGITAL_Y] = currBtnRT[E_CONTROLLER_DIGITAL_Y];
	lastBtnRT[E_CONTROLLER_DIGITAL_A] = currBtnRT[E_CONTROLLER_DIGITAL_A];

	//updating currRT[] values

	currJoyRT[E_CONTROLLER_ANALOG_LEFT_X] = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
	currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y] = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
	currJoyRT[E_CONTROLLER_ANALOG_RIGHT_X] = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
	currJoyRT[E_CONTROLLER_ANALOG_RIGHT_Y] = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);

	currBtnRT[E_CONTROLLER_DIGITAL_L1] = master.get_digital(E_CONTROLLER_DIGITAL_L1);
	currBtnRT[E_CONTROLLER_DIGITAL_L2] = master.get_digital(E_CONTROLLER_DIGITAL_L2);
	currBtnRT[E_CONTROLLER_DIGITAL_R1] = master.get_digital(E_CONTROLLER_DIGITAL_R1);
	currBtnRT[E_CONTROLLER_DIGITAL_R2] = master.get_digital(E_CONTROLLER_DIGITAL_R2);
	currBtnRT[E_CONTROLLER_DIGITAL_UP] = master.get_digital(E_CONTROLLER_DIGITAL_UP);
	currBtnRT[E_CONTROLLER_DIGITAL_DOWN] = master.get_digital(E_CONTROLLER_DIGITAL_DOWN);
	currBtnRT[E_CONTROLLER_DIGITAL_LEFT] = master.get_digital(E_CONTROLLER_DIGITAL_LEFT);
	currBtnRT[E_CONTROLLER_DIGITAL_RIGHT] = master.get_digital(E_CONTROLLER_DIGITAL_RIGHT);
	currBtnRT[E_CONTROLLER_DIGITAL_X] = master.get_digital(E_CONTROLLER_DIGITAL_X);
	currBtnRT[E_CONTROLLER_DIGITAL_B] = master.get_digital(E_CONTROLLER_DIGITAL_B);
	currBtnRT[E_CONTROLLER_DIGITAL_Y] = master.get_digital(E_CONTROLLER_DIGITAL_Y);
	currBtnRT[E_CONTROLLER_DIGITAL_A] = master.get_digital(E_CONTROLLER_DIGITAL_A);

}

bool btnRising(controller_digital_e_t button){

	if(currBtnRT[button] && !lastBtnRT[button]){
		return true;
	}
	else{
		return false;
	}
}

bool btnFalling(controller_digital_e_t button){

	if(!currBtnRT[button] && lastBtnRT[button]){
		return true;
	}
	else{
		return false;
	}
}

bool joystickRising(controller_analog_e_t stickChannel){

	if(currJoyRT[stickChannel] >= driveDeadThresh && lastJoyRT[stickChannel] < driveDeadThresh){
		return true;
	}
	else{
		return false;
	}
}

bool joystickFalling(controller_analog_e_t stickChannel){

	if(currJoyRT[stickChannel] < driveDeadThresh && lastJoyRT[stickChannel] >= driveDeadThresh){
		return true;
	}
	else{
		return false;
	}
}
/*
typedef enum _stackStates {
    stackNotRunning,
    stackPickupGround,
    stackPickupLoader,
    stackStationaryPrep,
    stackStationary,
    stackStack,
    stackDetach,
    stackClear,
    stackReturn,
    stackWall,
    stackTip
} tStackStates;
*/
#endif
