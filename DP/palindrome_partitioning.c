#include<stdio.h>
#include<limits.h>
#include<string.h>

int palindromePartition(char str[], int n)
{
	int DP[n][n];
	int P[n][n];
	
	int i, j, k, L;
	
	// 1 item	
	for(i = 0; i < n; i++) 
	{
        DP[i][i] = 0;
 	}
 
 	// 2 items
 	for(i = 0 ; i < n - 1; i++) 
	{
		if(str[i] == str[i+1])
		{
			P[i][i+1] = 1;
			DP[i][i+1] = 0;
		}
		else
		{
		 	DP[i][i+1] = 1;
		 	P[i][i+1] = 0;
		}
 	}
 
 	// from 3 items to n items
	for(L = 3; L <= n; L++) 
	{
    	for(i = 0; i < n - L + 1; i++) 
		{
        	int j = i + L - 1;
        	
        	P[i][j] = (str[i] == str[j]) && P[i+1][j-1]; 
        	
			if(P[i][j] == 1)
				DP[i][j] = 0;
			else
        	{
        		DP[i][j] = INT_MAX;
				for(k = i; k < j; k++)
        		{
        			int q = 1 + DP[i][k] + DP[k+1][j];
                	if (q < DP[i][j])
			  			DP[i][j] = q;
			  	}
			}	
     	}
 	}
	return DP[0][n-1];
}

int main()
{
	int n;
	char str[20];
	scanf("%s", str);
    printf("%d", palindromePartition(str,strlen(str)));
    return 0;
}
