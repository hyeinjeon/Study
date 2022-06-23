#include<stdio.h>
int get_integer(void);
int combination(int n, int r);
int factorial(int n);
int comb(int n, int r)
{
	printf("C(%d, %d) = %d\n", n, r, (factorial(n) / (factorial(r)*factorial(n-r))));
}
int main(void)
{
	int C10_5;
	C10_5 = comb(10,5);
	return 0;
}
int factorial(int n)
{
	if(n <= 1) return 1;
	else return (n*factorial(n-1));
}