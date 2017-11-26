int z = 77;
float y = 2.373;

task main()
{
	char x = 'a';  // 'a' -> 97
	x = 98;
	//int iy = (int)y;

	displayBigTextLine(3, "x is %c", x);
	displayBigTextLine(6, "y is %d", (int)y);
	displayBigTextLine(9, "z is %d", z);
	sleep(5000);

}
