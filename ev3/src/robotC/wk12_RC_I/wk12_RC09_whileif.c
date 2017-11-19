#pragma config(Sensor, S1,     ts,             sensorEV3_Touch)
#pragma config(Sensor, S3,     cs,             sensorEV3_Color)
#pragma config(Motor,  motorB,          lm,            tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rm,            tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define EDGE_VALUE 30

task main()
{
	int i=0;

	while(i<5){

				setMotorSpeed(lm, -50);
				setMotorSpeed(rm, 50);
				sleep(500);

				setMotorSpeed(lm, 50);
				setMotorSpeed(rm, -50);
				sleep(500);

				i++;
	}

	playSound(soundBlip);
	sleep(4000);

}
