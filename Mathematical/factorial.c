#include<stdio.h>

int factorial(int n)
{
	int res = 1;
	int i;
	for(i = 1; i <= n; i++)
		res *= i;
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", factorial(n));
	return 0;
}
