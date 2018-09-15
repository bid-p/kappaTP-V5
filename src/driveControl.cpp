#include "drive.hpp"

pros::Motor *driveR1;
pros::Motor *driveR2;
pros::Motor *driveR3;
pros::Motor *driveL1;
pros::Motor *driveL2;
pros::Motor *driveL3;

void initDriveMotors(){
  driveR1 = new pros::Motor(MPORT_DRIVE_R1, pros::E_MOTOR_GEARSET_18, 0);
  driveR2 = new pros::Motor(MPORT_DRIVE_R2, pros::E_MOTOR_GEARSET_18, 0);
  driveR3 = new pros::Motor(MPORT_DRIVE_R3, pros::E_MOTOR_GEARSET_18, 0);
  driveL1 = new pros::Motor(MPORT_DRIVE_L1, pros::E_MOTOR_GEARSET_18, 0);
  driveL2 = new pros::Motor(MPORT_DRIVE_L2, pros::E_MOTOR_GEARSET_18, 0);
  driveL3 = new pros::Motor(MPORT_DRIVE_L3, pros::E_MOTOR_GEARSET_18, 0);
}

void powerDrive(int left, int right){
  driveL1->move(left);
  driveL2->move(left);
  driveL3->move(left);
  driveR1->move(right);
  driveR2->move(right);
  driveR3->move(right);
}

void changeDriveState(tDriveStates driveState){
	switch (currDriveState) {
	case driveNotRunning:
		powerDrive(0,0);
		break;
	}
	currDriveState = driveState;
}

void checkDriveState(){
	if ( (currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y] < driveDeadThresh && joystickFalling(E_CONTROLLER_ANALOG_RIGHT_Y) ) || ( currJoyRT[E_CONTROLLER_ANALOG_RIGHT_Y] < driveDeadThresh && joystickFalling(E_CONTROLLER_ANALOG_LEFT_Y) ) ){
		changeDriveState(driveNotRunning);
	}
	else {
		changeDriveState(driveRunning);
	}
}

void driveTank(){
	int leftPower;
	int rightPower;

	leftPower = currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y];
	rightPower = currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y];

	powerDrive(leftPower, rightPower);
}

/*
void driveArcade() //Arcade Drive Control w/ deadzone threshold
{
  drivePower = currJoyRT[E_CONTROLLER_ANALOG_LEFT_Y];
  turnPower = currJoyRT[E_CONTROLLER_ANALOG_RIGHT_X];
  powerDrive(drivePower + turnPower, drivePower - turnPower);
}
*/

void updateDrive(){
	while(true){
		switch (currDriveState) {
		case driveNotRunning:
			delay(10);
			break;

		case driveRunning:
			driveTank();
			delay(10);
			break;

		case driveHolding:
			delay(10);
			break;
		}
	}
}
