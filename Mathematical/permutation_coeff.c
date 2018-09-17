#include<stdio.h>

// nPr = n!/(n-r)! = n * n-1 * n-2 * ..... * n-r+1

int nPr(int n, int r)
{
	int res = 1;
	int i;
	for(i = 0; i < r; i++)
		res *= (n-i);
	return res;
}

int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	printf("%d", nPr(n, r));
	return 0;
}
