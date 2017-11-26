
task main()
{

	int data[5][5];
	int data1[5][5];
	int i,j;

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			data[i][j]=0;

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			data1[i][j]=i+j;

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			displayStringAt((j+1)*10, 100-(i+1)*10, "%d ", data[i][j]);
	sleep(5000);

	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			displayStringAt((j+1)*10, 100-(i+1)*10, "%d ", data1[i][j]);
	sleep(5000);

}
