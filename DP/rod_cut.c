#include<stdio.h>
 
int max(int a, int b)
{
	return (a > b)? a : b;
}

int cutRod(int length, int rod[], int n)
{
	int DP[n + 1][length + 1];
	int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= length; j++)
        {
            if(i == 0 || j == 0)
                DP[i][j] = 0;  
			else if(i > j)
            	DP[i][j] = DP[i-1][j];
            else
            	DP[i][j] = max(DP[i-1][j], rod[i] + DP[i][j-i]);
        }
    }
    return DP[n][length];
}

int main()
{
    int length, i;
	int rod[100];
	scanf("%d", &length);
	for(i = 1; i <= length; i++)
		scanf("%d", &rod[i]);
	printf("%d", cutRod(length, rod, length));
    return 0;
}


