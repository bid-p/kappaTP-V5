#include "main.h"

pros::Motor *lift1;

void initLiftMotors(){
	lift1 = new pros::Motor(MPORT_LIFT, pros::E_MOTOR_GEARSET_36, 0);
}

void setLift(int power){
	lift1->move(power);
}

void checkLiftState(){
	if (btnRising(E_CONTROLLER_DIGITAL_R1)){
		currLiftState = liftRising;
	}
	if (btnFalling(E_CONTROLLER_DIGITAL_R1)){
		currLiftState = liftHolding;
	}
	if (btnRising(E_CONTROLLER_DIGITAL_R2)){
		currLiftState = liftFalling;
	}
	if (btnFalling(E_CONTROLLER_DIGITAL_R2)){
		currLiftState = liftHolding;
	}
}

void updateLift(){

	switch (currLiftState) {
	case liftNotRunning:
		break;

	case liftRising:
		setLift(127);
		break;

	case liftFalling:
		setLift(-127);
		break;

	case liftHolding:
		liftTarget = lift1->get_position();
		lift1->move_absolute(liftTarget, 200);
		break;

	case liftPickupGround:
		liftTarget = 50;
		lift1->move_absolute(liftTarget, 200);
		break;

	case liftPickupFlip:
		liftTarget = 50;
		lift1->move_absolute(liftTarget, 200);
		break;

	case liftHighGoal:
		liftTarget = 50;
		lift1->move_absolute(liftTarget, 200);
			break;

	case liftLowGoal:
		liftTarget = 50;
		lift1->move_absolute(liftTarget, 200);
		break;
	}
}
