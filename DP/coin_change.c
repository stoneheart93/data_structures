#include<stdio.h>
 
int coinChange(int amount, int coins[], int n)
{
	int DP[n + 1][amount + 1];
	int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= amount; j++)
        {
            if(i == 0)
                DP[i][j] = 0;  
			else if(j == 0)
                DP[i][j] = 1;
            else if(i == 1)
            {
            	if(j % coins[i] == 0)
            		DP[i][j] = 1;
            	else
            		DP[i][j] = DP[i-1][j];
			}
            else 
			{
				if(coins[i] > j)
            		DP[i][j] = DP[i-1][j];
            	else
            		DP[i][j] = DP[i-1][j] + DP[i][j-coins[i]];
        	}
        }
    }
    return DP[n][amount];
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


