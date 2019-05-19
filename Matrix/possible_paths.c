#include<stdio.h>

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

int possible_paths(int m, int n)
{
	return nCr(m + n - 2, m - 1);
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d", possible_paths(m, n));
	return 0;
}
