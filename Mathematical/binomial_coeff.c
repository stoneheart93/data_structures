#include<stdio.h>

// nCr = n!/[(n-r)! * r!] = [n * n-1 * n-2 * ..... * n-r+1] / [r * r-1 * .. 1]

int nCr(int n, int r)
{
	int res = 1;
	int i;
	for(i = 0; i < r; i++)
	{
		res *= (n-i);
		res /= (i+1);
	}
	return res;
}

int main()
{
	int n, r;
	scanf("%d%d", &n, &r);
	printf("%d", nCr(n, r));
	return 0;
}
