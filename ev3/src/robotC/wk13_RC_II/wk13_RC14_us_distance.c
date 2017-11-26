#pragma config(Sensor, S1, ts, sensorEV3_Touch)
#pragma config(Sensor, S2, gs, sensorEV3_Gyro)
#pragma config(Sensor, S3, cs, sensorEV3_Color)
#pragma config(Sensor, S4, us, sensorEV3_Ultrasonic)
#pragma config(Motor, motorB,lm, tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor, motorC,rm, tmotorEV3_Large, PIDControl, driveRight, encoder)
/*!!Code automatically generated by 'ROBOTC' configuration wizard  !!*/

void go(int speed_l, int speed_r);

task main()
{
	int dist;
	while(1){
		dist=getUSDistance(us);
		if(dist<10){
			go(-30,-30);
			sleep(1000);
			go(0,0);
			go(30,-30);
			sleep(700);
			go(0,0);
		}
		else go(30,30);
	}	// while
}  // main

void go(int speed_l, int speed_r)
{
	setMotorSpeed(lm, speed_l);
	setMotorSpeed(rm, speed_r);
}
