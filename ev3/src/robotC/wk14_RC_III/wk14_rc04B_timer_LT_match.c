#pragma config(Sensor, S3,     cs,             sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorB,          lm,            tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rm,            tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*!!Code automatically generated by 'ROBOTC' configuration wizard  !!*/

task main()
{
	const int black = 1;
	int speed = 30;
	float t;

	while(getColorName(cs) != black)
	{
		setMotorSpeed(lm, speed);
		setMotorSpeed(rm, speed);
	}

	while(getColorName(cs) == black)
	{
		setMotorSpeed(lm, speed);
		setMotorSpeed(rm, speed);
	}

	clearTimer(T1);  // initialization of timer

	setMotorSpeed(lm, speed);
	setMotorSpeed(rm, speed);
	sleep(100);  // 0.1 sec

	while(getColorName(cs) != black)
	{
		setMotorSpeed(lm, speed);
		setMotorSpeed(rm, speed);
	}

	t = time1[T1];
	displayBigTextLine(5, "Record = %.2f sec", t/1000);

	setMotorSpeed(lm, 0);
	setMotorSpeed(rm, 0);

	sleep(10000);

}
