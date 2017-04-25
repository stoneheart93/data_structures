#include<stdio.h>

int maxDet(int n)
{
	return (2 * n * n * n);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", maxDet(n));
	return 0;
}
