#include "odom.hpp"

void calcAngVel(){
	angularVelocity = (theta-prevTheta)/5;
}

void trackPos(){

	float chassisWidth = 5;
	float dR;
	float dL;
	float dM;
	float dS;
	float dTheta;
	float avgTheta;
	float dX;
	float dY;

	float lastEncoderValueL = 0;
	float lastEncoderValueR = 0;
	//float lastEncoderValueM = 0;
	float currentEncoderValueL = 0;
	float currentEncoderValueR = 0;
	//float currentEncoderValueM = 0;

	float lastVelCalcTime = millis();

	while(true){

		prevTheta = theta;

		currentEncoderValueR = (driveR1->get_raw_position(&timeNow) + driveR2->get_raw_position(&timeNow) + driveR3->get_raw_position(&timeNow))/3;
		currentEncoderValueL = (driveL1->get_raw_position(&timeNow) + driveL2->get_raw_position(&timeNow) + driveL3->get_raw_position(&timeNow))/3;
		//currentEncoderValueM = SensorValue[trackerH];

		// Can multiply by a scalar to get the values in inches, or whatever unit I want x and y coordinates to be in.
		dR = currentEncoderValueR - lastEncoderValueR;
		dL = currentEncoderValueL - lastEncoderValueL;
		//dM = currentEncoderValueM - lastEncoderValueM;

		dR *= ((4.125 * 3.141592) / 360);
		dL *= ((4.125 * 3.141592) / 360);
		//dM *= ((2.875 * PI) / 360);

		dTheta = (dR - dL) / chassisWidth;  // Change in angle robot turned since last checked.
		//dS *= 2.0 * sin(dTheta / 2.0) / dTheta;  // arc based distance robot traveled since last checked.

		avgTheta = theta + dTheta / 2.0;  // Angle robot is assumed to have been facing when moving dS.

		// Change in x and y position since last checked.
		dX = dS * cos(avgTheta) + dM * sin(avgTheta);
		dY = dS * sin(avgTheta) - dM * cos(avgTheta);

		// Update current robot position.
		//xPos += dX;
		//yPos += dY;
		theta += dTheta;

		lastEncoderValueL = currentEncoderValueL;
		lastEncoderValueR = currentEncoderValueR;
		//lastEncoderValueM = currentEncoderValueM;

		//writeDebugStreamLine("X = %f   Y = %f   Heading = %f", xPos, yPos, theta);

		if (millis() > lastVelCalcTime + 500) {
    	calcAngVel();
    	lastVelCalcTime = millis();
		}

		delay(5);
	}
}
