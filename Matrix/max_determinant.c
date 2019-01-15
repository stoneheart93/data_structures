/*
A matrix of size n has maximum determinant when matrix is of the form
n n 0
0 n n
n 0 n
*/
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
