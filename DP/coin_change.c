#include<stdio.h>
 
int coinChange(int amount, int coins[], int n)
{
	int dp[n + 1][amount + 1];
	int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= amount; j++)
        {
            if(i == 0)
                dp[i][j] = 0;  
			else if(j == 0)
                dp[i][j] = 1;
            else if(coins[i] > j)
            	dp[i][j] = dp[i-1][j];
            else
            	dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
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
	printf("%d", coinChange(amount, coins, n));
    return 0;
}


