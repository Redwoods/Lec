#pragma config(Sensor, S1,     ts,             sensorEV3_Touch)
#pragma config(Sensor, S2,     gs,             sensorEV3_Gyro)
#pragma config(Sensor, S3,     cs,             sensorEV3_Color)
#pragma config(Sensor, S4,     us,             sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          lm,            tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rm,            tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard   !!*//

#define EDGE_VALUE 30

task main()
{
	int speed_l, speed_r, curval;
	int initval = getGyroDegrees(gs);

	while(1)
	{ // Gyro driving
		if(getColorReflected(cs)>EDGE_VALUE)
		{
			curval = getGyroDegrees(gs) - initval;
			speed_l = 25 - curval;
			speed_r = 25 + curval;
			setMotorSpeed(lm, speed_l);
			setMotorSpeed(rm, speed_r);
		}
		else
		{ // stop
			setMotorSpeed(lm,0);
			setMotorSpeed(rm,0);
			sleep(2000);

			setMotorSpeed(lm,50);
			setMotorSpeed(rm,50);

			// MilDang
			while(1) {
				if(getUSDistance(us)<=10) {
					setMotorSpeed(lm,-50);
					setMotorSpeed(rm,-50);
				}
				else {
					setMotorSpeed(lm,50);
					setMotorSpeed(rm,50);
				}
			}
		}
	}
}
