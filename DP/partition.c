#include<stdio.h>
 
int subsetSum(int sum, int a[], int n)
{
	int DP[n + 1][sum + 1];
	int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= sum; j++)
        {
            if(i == 0)
                DP[i][j] = 0;  
			else if(j == 0)
                DP[i][j] = 1;
            else if(a[i] > j)
            	DP[i][j] = DP[i-1][j];
            else
            	DP[i][j] = DP[i-1][j] || DP[i-1][j-a[i]];
        }
    }
    return DP[n][sum];
}

int partition(int a[], int n)
{
	int i, sum = 0;
	
	for(i = 1; i <= n; i++)
		sum += a[i];
	if(sum % 2 == 0)
		return subsetSum(sum/2, a, n);
	else
		return 0;
}

int main()
{
    int n;
	int a[100];
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d", partition(a, n));
    return 0;
}
