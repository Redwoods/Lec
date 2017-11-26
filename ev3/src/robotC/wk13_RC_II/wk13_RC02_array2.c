
task main()
{
	int data[5];
	int i;

	for(i=0;i<5;i++){
		data[i]=0;
	}

	for(i=0;i<5;i++){
		displayBigTextLine(5,"data[%d] = %d", data[0], i, data[i]);
		sleep(2000);
	}
}
