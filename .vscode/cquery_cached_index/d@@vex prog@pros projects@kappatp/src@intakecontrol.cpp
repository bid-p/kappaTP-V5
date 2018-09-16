#include "init.hpp"
#include "ports.hpp"
#include "intake.hpp"

using namespace pros;

pros::Motor *intake;

void initIntakeMotors(){
  intake = new pros::Motor(MPORT_INTAKE, pros::E_MOTOR_GEARSET_18, 0);
}

void setIntake(int power){
  intake->move(power);
}

void setIntakePosition(int position){
  intake->move_absolute(position, 200);
}

void checkIntakeState(){
	if (btnRising(E_CONTROLLER_DIGITAL_L1)){
		currIntakeState = intakeOpen;
	}
  if (btnRising(E_CONTROLLER_DIGITAL_L2)){
		currIntakeState = intakeClose;
	}
}

void updateIntake(){

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
