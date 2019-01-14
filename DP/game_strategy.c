#include<stdio.h>

int max(int a, int b)
{
	return (a > b)? a : b;
}

int min(int a, int b)
{
	return (a < b)? a : b;
}

int win_game(int a[], int n)
{
	int DP[n][n];
	int i, j, L;
	
	// 1 item	
	for(i = 0; i < n; i++) 
	{
        DP[i][i] = a[i];
 	}
 
 	// 2 items
 	for(i = 0 ; i < n - 1; i++) 
	{
     	DP[i][i+1] = max(a[i], a[i+1]);
 	}
 
 	// from 3 items to n items
	for(L = 3; L <= n; L++) 
	{
    	for(i = 0; i < n - L + 1; i++) 
		{
        	int j = i + L - 1;
         	DP[i][j] = max(a[i] + min(DP[i+2][j], DP[i+1][j-1]), 
			 			   a[j] + min(DP[i][j-2], DP[i+1][j-1]));
     	}
 	}
	return DP[0][n-1];
}

int main()
{
	int n, i;
	int a[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    printf("%d", win_game(a,n));
    return 0;
}
