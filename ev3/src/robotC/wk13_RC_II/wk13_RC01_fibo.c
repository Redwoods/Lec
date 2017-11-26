
task main()
{

	int n=10;
	displayBigTextLine(5,"fibo(%d) = %d", n, fibo(n));
	sleep(5000);

}

int fibo(int n){
	if(n<=1) return n;
	return fibo(n-2)+fibo(n-1);
}
