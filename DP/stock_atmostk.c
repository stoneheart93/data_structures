/*

profit[t][j] = max( profit[t][j-1],
					a[j] - a[m] + profit[t-1][m] for m all over [0, j-1] )
					
max(a[j] - a[m] + profit[t-1][m])
= a[j] + max( profit[t-1][m] - a[m])
= a[j] + max(prevDiff, profit[t-1][j-1] - a[j-1])
	where prevDiff = profit[t-1][m] - a[m] for m all over [0, j-1]
	
Hence, profit[t][j] = max( profit[t][j-1],
						   a[j] + max(prevDiff, profit[t-1][j-1] - a[j-1]) )
						
*/

#include<stdio.h>
#include<limits.h>

int max(int a, int b)
{
	return (a > b) ? a : b;	
}

int transaction(int a[], int n, int k)
{
	int profit[k+1][n];
	
	int t, j;
	for(t = 0; t <= k; t++) 
    	profit[t][0] = 0; 
  
    for(j = 0; j < n; j++) 
    	profit[0][j] = 0; 
  
    for(t = 1; t <= k; t++) 
	{ 
        int prevDiff = INT_MIN; 
        for(j = 1; j < n; j++) 
		{ 
            prevDiff = max(prevDiff, profit[t-1][j-1] - a[j-1]); 
            profit[t][j] = max(profit[t][j-1], a[j] + prevDiff); 
        } 
    } 
  
    return profit[k][n - 1]; 
}

int main() 
{
    int n, i, k;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	printf("%d", transaction(a, n, k));
	return 0;
}

