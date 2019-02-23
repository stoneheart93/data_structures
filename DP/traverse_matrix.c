#include<stdio.h>

int traverse(int m, int n)
{
	int DP[m][n];
	
	int i, j;
	
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(i == 1 || j == 1)
				DP[i][j] = 1;
			else
				DP[i][j] = DP[i][j-1] + DP[i-1][j];
		}
	}
	return DP[m][n];
}

int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d", traverse(m, n));
	return 0;
}
