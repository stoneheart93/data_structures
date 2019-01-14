#include<stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int wineProblem(int a[], int n)
{
	int DP[n][n];
	int prefix[n];
	
	int i, j, L;

	//calculate prefix sum
	prefix[0] = a[0];
	for(i = 1; i < n; i++) 
	{
    	prefix[i] = prefix[i-1] + a[i];
  	}
	
	// 1 item
	for(i = 0; i < n; i++) 
	{
    	DP[i][i] = a[i];
  	}

	// 2 items
  	for(i = 0; i < n -1; i++) 
	{
		DP[i][i+1] = min(a[i], a[i+1]) + 2*max(a[i], a[i+1]);
  	}

  	
  	// from 3 to N items
	for(L = 3; L <= n; L++) 
	{
    	for(i = 0; i < n -L + 1; i++) 
		{
     		int j = i + L -1;
     		int iPlus1_jMinus1 = prefix[j] - prefix[i] - a[j];
     		DP[i][j] = max( (a[i] + DP[i+1][j] + iPlus1_jMinus1 + a[j]) ,
                       		(a[j] + DP[i][j-1] + iPlus1_jMinus1 + a[i]));
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
    printf("%d", wineProblem(a,n));
    return 0;
}
