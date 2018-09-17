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

int catalan(int n)
{
	// Cn = 2nCn/(n+1);
	return (nCr(2*n, n)) / (n+1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", catalan(n));
	return 0;
}
