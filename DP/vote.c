#include<stdio.h>

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
}

int canVote(int a[], int n, int x)
{
	int sum = 0;
	int i, j;
	
	int DP[n + 1][x + 1];
	
	for(i = 1; i <= n; i++)
		sum += a[i];
		
	for(i = 0; i <= n; i++)
	{
		for(j = 0; j <= x; j++)
		{
			if(i == 0)
				DP[i][j] = 0;
			else if(j == 0)
				DP[i][j] = 1;
			else if(a[i] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = max(DP[i - 1][j], a[i] + DP[i - 1][j - a[i]]);
		}
	}
	
	int s1 = DP[n][x];
	
	return (sum - s1 <= x);
}

int main()
{
	int x, n, i;
	int a[20];
	scanf("%d", &x);
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d", canVote(a, n, x));
    return 0;
}
