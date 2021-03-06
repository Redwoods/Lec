#pragma config(Motor,  motorB,          lm,            tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rm,            tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int i=0;

	do
	{

		setMotorSpeed(lm, -50);
		setMotorSpeed(rm, 50);
		sleep(500);

		setMotorSpeed(lm, 50);
		setMotorSpeed(rm, -50);
		sleep(500);

		i++;
	}	while(i<5);

	setMotorSpeed(lm, 0);
	setMotorSpeed(rm, 0);
	playSound(soundBeepBeep);
	sleep(1000);

}
