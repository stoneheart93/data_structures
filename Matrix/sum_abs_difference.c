#include<stdio.h>

int sumAbsDiff(int n)
{
	n--;
	int sum1 = (n * (n + 1)) / 2;
	int sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
	return (sum1 + sum2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", sumAbsDiff(n));
	return 0;
}
