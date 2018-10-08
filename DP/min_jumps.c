#include<stdio.h>
#include<limits.h>

int min(int a, int b)
{
	return (a < b) ? a : b;
}
int minJumps(int jumps[], int n)
{
    int i, j;
    int dp[n];
    dp[0] = 0;
 
    for(i = 1; i < n; i++)
        dp[i] = INT_MAX;
 
    for(i = 0; i < n - 1; i++)
    {
        for(j = 1; j <= jumps[i] && i + j < n; j++)
        {
            dp[i+j] = min(dp[i+j], 1 + dp[i]);
        }
    }
 
    return dp[n-1];
}
 
int main()
{
	int a[100];
    int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", minJumps(a, n));
    return 0;
}
