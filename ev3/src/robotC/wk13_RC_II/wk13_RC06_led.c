task main()
{
	int col;

	for(col=0;col<10;col++) {
		setLEDColor(col);
		sleep(3000);
		setLEDColor(ledOff);
		sleep(1000);
	}

	setLEDColor(ledOff);
}
