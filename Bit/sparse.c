#include<stdio.h>

int isSparse(int n)
{
	if(n & (n >> 1))
		return 0;
	else
		return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	if(isSparse(n))
		printf("%d is a sparse number", n);
	else
		printf("%d is not a sparse number", n);
	return 0;
}
