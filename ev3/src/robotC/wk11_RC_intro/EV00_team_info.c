task main()
{
	
	string s1 = "EV00";
	string s2 = "Redwoods, Chaos";
	int acNum = 77;
	string s31 = "Stay hungry, ";
	string s32 = "stay foolish.";

	displayBigTextLine(0, "Show %s Info.", s1);
	displayBigTextLine(3, "Name: %s", s2);
	displayBigTextLine(6, "acNUM: %d", acNum);
	displayBigTextLine(9, s31);
	displayBigTextLine(11, s32);
	sleep(5000);

}
