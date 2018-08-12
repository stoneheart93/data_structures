#include<stdio.h>
#include<limits.h>
 
int min(int a, int b)
{
	return (a < b)? a: b;
}
 
int minCoinChange(int amount, int coins[], int n)
{
	int dp[n + 1][amount + 1];
	int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= amount; j++)
        {
            if(i == 0)
                dp[i][j] = INT_MAX;  
			else if(j == 0)
                dp[i][j] = 0;
            else if(i == 1)
            {
            	if(j % coins[i] == 0)
            		dp[i][j] = j / coins[i];
            	else
            		dp[i][j] = dp[i-1][j];
			}
            else
			{
				if(coins[i] > j)
            		dp[i][j] = dp[i-1][j];
            	else
            		dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-coins[i]]);
            }
        }
    }
    return dp[n][amount];
}

int main()
{
    int amount, n;
	int coins[100];
	int i;
	scanf("%d", &amount);
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &coins[i]);
	printf("%d", minCoinChange(amount, coins, n));
    return 0;
}


